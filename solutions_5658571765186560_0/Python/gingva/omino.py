__author__ = 'dtrUdev'
import sys


def main(fn1, fn2):
    with open(fn1) as f:
        with open(fn2, 'w') as g:
            ncases = int(f.next().strip())
            for n in range(ncases):
                X,R,C = map(int,f.next().strip('\r\n').split())
                r = solve(X,R,C)
                names = ['RICHARD', 'GABRIEL']
                print >> g, 'Case #%d: %s'%(n+1, names[r])



polyminoesFlat = dict()

def polyominoGen(X):
    # start with 1
    # add one block to each border
    # translate to min x min y
    # rotate 4 times and flip each time and translate
    # select minimal == canonical repr
    # associate canonical with all rotations
    if X == 1 :
        return {((0,0),) : ((0,0),)}
    if X == 2:
        flat = [((0,0), (1,0)),
                ((0,0), (0,1)),]
        flat.sort()
        return dict( (f,flat[0]) for f in flat)

    if X == 3:
        corner = [((0,0), (0,1), (1,0)), #corner
                ((0,0), (0,1), (1,1)), #corner
                ((0,0), (1,0), (1,1)), #corner
                ((0,1), (1,0), (1,1)), #corner
                 ]
        line =  [((0,0), (0,1), (0,2)), #line
                ((0,0), (1,0), (2,0)), #line
                ]

        corner.sort()
        line.sort()
        can = dict( (f,corner[0]) for f in corner)
        can.update(dict( (f,line[0]) for f in line))
        return can

def translate0(poly):
    minX = min((x for (x,y) in poly))
    minY = min((y for (x,y) in poly))
    return tuple((x-minX, y-minY) for (x,y) in poly)
def flipX(poly):
    return tuple((-x, y) for (x,y) in poly)
def rotateCW(poly):
    return tuple((y, -x) for (x,y) in poly)
def normalize(poly):
    return tuple(sorted(poly))
def norm(poly):
    return normalize(translate0(poly))
def gen4Neighbours((x,y)):
    return [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]

def rotateAndFlip(poly):
    polySet = set()
    for rot in range(4):
        if rot > 0:
            poly = norm(rotateCW(poly))
        polySet.add(poly)
        polyF = norm(flipX(poly))
        polySet.add(polyF)
    return polySet

def up1Dim(polys):
    canonical = {}
    for poly in polys:
        for ref in poly:
            for brick in gen4Neighbours(ref):
                if brick not in poly:
                    candidate = norm(poly + (brick,))
                    polySet = rotateAndFlip(candidate)
                    can = min(polySet)
                    for i in polySet:
                        canonical[i] = can
        return canonical

polyominoes = [polyominoGen(1), polyominoGen(2), polyominoGen(3) ]
test = up1Dim(set(polyominoes[0].values()))
assert test == polyominoes[1]
test = up1Dim(set(polyominoes[1].values()))
assert test == polyominoes[2]

for x in range(4):
    polyominoes.append(up1Dim(set(polyominoes[-1].values())))



def solve(X,R,C):
  assert X > 0
  if R>C:
      R,C = C,R
  canonicals = polyominoes[X-1]
  if (R*C)%X <> 0:
      return 0 # simple cell count
  if X>R and X>C:
      return 0 # the rod breaks
  if X >= 7:
      return 0 # there is a hole piece that can be chosen by GABRIEL
  if X==1:
      return 1
  if X==2:
      return 1 # the 0 case is handled by cell count above. bipartite matching on a chess board
  if X==3:
      return (R,C) <> (1,3) # 3,2 and 3,3 ok
  if X==4:
      return (R,C) in [(3,4), (4,4)] # 3,4 can be done with 3I, 2L+1S, 1L+2T therefore covers all shapes. add one I for 4,4
  if X>4:
      return enumSearch(X,R,C)

def enumSearch(X,R,C):
    # do a recursive search to generate R,C grids with no holes.
    # once we find enough solutions that we have used each canonical piece we are done and return 1
    #define the state space as set of all cells, set of used cells, set of free cells, set of canon shapes used so far, frontier where to put new pieces
    # neighbourhood is all flat shapes (prioritize the ones we have not used) placed overlapping the frontier
    # the frontier starts in th 0,0 corner then all adjacent cells to existing pieces.
    # the shapes have to not overlap or cross outside bounds.
    # use a translate method to place the piece overlapping with frontier and not with used cells
    # detect holes to trim the search space
    pass
if __name__ == '__main__':
    main('D-test.in', 'D-test.out')
    main('D-small-attempt0.in', 'D-small-attempt0.out')
    #main('D-large.in', 'D-large.out')

