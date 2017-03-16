#!/usr/bin/python3

import sys
import collections

X_MAX = 300
Y_MAX = 300
STEP_MAX = 500

T = int(sys.stdin.readline())
caseNum = 0

directions = [(1, 0, 'E'), (-1, 0, 'W'), (0, 1, 'N'), (0, -1, 'S')]
step_dict = {'E': (1, 0), 'W': (-1, 0), 'N': (0, 1), 'S': (0, -1)}

def solve(X_final, Y_final):
    global directions
    global step_dict
    X_final += 100
    Y_final += 100
    X, Y = 100, 100
    field = [[[None] for y in range(Y_MAX+1)] for x in range(X_MAX+1)]
    field[X][Y][0] = '@' # over
    
    # BFS
    q = collections.deque()
    q.append( (X, Y, 0) )
    while True:
        X, Y, t = q.popleft()
        # print("X, Y, t =", X-100, Y-100, t)
        if (X == X_final) and (Y == Y_final):
            ans = ""
            while t > 0:
                # print("X, Y, t, letter =", X, Y, t, field[X][Y][t])
                letter = field[X][Y][t]
                ans = letter + ans
                dx, dy = step_dict[letter]
                X -= dx * t
                Y -= dy * t
                t -= 1
            return ans
        t += 1 # step size
        for dx, dy, letter in directions:
            if (X+t*dx < 0) or (X+t*dx > X_MAX): continue
            if (Y+t*dy < 0) or (Y+t*dy > Y_MAX): continue
            manjka = (t+1) - len(field[X+dx*t][Y+dy*t])
            for i in range(manjka):
                field[X+dx*t][Y+dy*t].append(None)
            if not (field[X+dx*t][Y+dy*t][t] is None): continue
            field[X+dx*t][Y+dy*t][t] = letter
            q.append( (X+dx*t, Y+dy*t, t) )

while caseNum < T:
    caseNum += 1
    X, Y = map(int, sys.stdin.readline().strip().split(' '))
    print("Case #{0}: {1}".format(caseNum, solve(X, Y)))
