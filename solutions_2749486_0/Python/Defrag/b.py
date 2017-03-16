#!/usr/bin/env python

import numpy, matplotlib.pyplot as plt

A = numpy.array

directions = {
    -1 +  0j  :  'W',
     0 + -1j  :  'S',
    +1 +  0j  :  'E',
     0 + +1j  :  'N',
    # A([+1,  0]),
    # A([-1,  0]),
    # A([ 0, +1]),
    # A([ 0, -1]),
}

# x >= y
# x>0, y>0


def intline(): return map(int, raw_input().split())

N, = intline()

# def solve(pos, jump):
#     if jump==0:
#         return 'g' if pos==0 else 'b' # good / bad
#     for direction in directions:
#         out = solve(pos+direction*jump, jump-1)
#         if out.startswith('g'):
#             return out+directions[direction]

#     return 'b' # bad


# for caseNum in xrange(N):
#     X, Y = intline()

#     flipY = False
#     flipX = False

#     if Y<0: flipY=True; Y=-X
#     if X<0: flipX=True; X=-X

#     pos = X*1 + Y*1j


#     answer = pos
#     print 'Case #{0}: {1}'.format(caseNum+1, answer)



positionMap = { 0+0j : 'X' }

iterations = 24 # TODO
positions = set([0, 0])
for iteration in xrange(1,iterations+1):
    # print 'it', iteration
    newPositions = set()
    for pos in positions:
        for direction in directions:
            newPos = pos+direction*iteration
            # if newPos not in positions:
            if len(positionMap[pos]) == iteration:
                newPositions.add(newPos)
                positionMap[newPos] = positionMap[pos] + directions[direction]
    positions = positions.union(newPositions)


def verify(string, pos):
    revMap = { val:key for key,val in directions.iteritems() }
    p = 0+0j
    for stepsize, compas in enumerate(string):
        p+= (stepsize+1) * revMap[compas]
        # print stepsize, revMap[compas]
    print p==pos, p, pos

# verify('ENSWN', 3+4j)

for caseNum in xrange(N):
    X, Y = intline()

    # flipY = False
    # flipX = False

    # if Y<0: flipY=True; Y=-X
    # if X<0: flipX=True; X=-X

    pos = X*1 + Y*1j


    answer = positionMap[pos][1:]
    print 'Case #{0}: {1}'.format(caseNum+1, answer)
    # verify(answer, pos)



# xs = [ x.real for x in positions ]
# ys = [ x.imag for x in positions ]

# print positionMap
# print xs, ys
# s = [20*2**n for n in range(len(x))]
# plt.scatter(xs, ys)
# plt.show()
