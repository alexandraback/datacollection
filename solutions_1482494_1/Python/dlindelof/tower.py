from sys import stdin

def next_move(levels, stars):
    """
    >>> next_move([[(0,5),0],[(0,1),0],[(1,1),0],[(4,7),0],[(5,6),0]],0)
    [[[(0, 5), 1], [(0, 1), 0], [(1, 1), 0], [(4, 7), 0], [(5, 6), 0]], 1]
    """
    for level in levels:
        if level[0][1] <= stars and level[1] != 2:
            stars = stars + 2 - level[1]
            level[1] = 2
            return [levels, stars]
    for level in levels:
        if level[0][0] <= stars and level[1] == 0:
            stars = stars + 1
            level[1] = 1
            return [levels, stars]
    return None

def game(levels):
    """
    >>> game([(0,5),(0,1),(1,1),(4,7),(5,6)])
    6
    >>> game([(0,1),(0,2)])
    3
    >>> game([(2,2),(0,0),(4,4)])
    3
    >>> game([(1,1)])
    
    """
    stars = 0
    n_moves = 0
    levels = [[level,0] for level in levels]
    move = next_move(levels, stars)
    while move:
        n_moves = n_moves + 1
        stars = move[1]
        move = next_move(move[0], move[1])
    if (stars == 2*len(levels)):
        return n_moves
    else:
        return None
    
def main():
    N = int(stdin.readline())
    for case in range(1,N+1):
        n_levels = int(stdin.readline())
        levels = []
        for i in range(n_levels):
            levels.append(tuple([int(x) for x in stdin.readline().split()]))
        levels.sort(lambda x,y:cmp(y[1],x[1]))
        moves = game(levels)
        if moves:
            print "Case #%d: %d" % (case, moves)
        else:
            print "Case #%d: Too Bad" % case

if __name__ == "__main__":
    main()
