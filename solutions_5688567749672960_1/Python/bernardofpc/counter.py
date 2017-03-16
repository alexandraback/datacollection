def digits(n):
    return [int(j) for j in str(n)]

def num_of_digits(l):
    if l == []: return 0
    if len(l) == 1: return l[0]
    return 10*num_of_digits(l[:-1]) + l[-1]

def time_10(k):
    if k <= 0: return 0
    if k == 1: return 10
    half = k//2
    otherhalf = k - half
    return time_10(k-1) + 10**otherhalf + 10**half - 1

#print([time_10(j) for j in range(10)])

def solve(n):
    if n <= 19: return n

    digs = digits(n)
    if digs[-1] == 0: return 1 + solve(n-1)

    ndig = len(digs)
    t10 = time_10(ndig-1)
    if n == 10**(ndig-1): return t10

    half = ndig//2
    # print('\nSolving {} {} {}'.format(digs,half, num_of_digits(digs[:half])))
    upper = num_of_digits(list(reversed(digs[:half])))
    lower = num_of_digits(digs[half:])

    if upper == 1: return t10 + lower
    else: return t10 + upper + lower

def bf(n):
    stack = [(1,0,1)]
    visited = {}
    while len(stack) > 0:
        x,px,lx = stack[0]
        stack = stack[1:]
        # if lx <= 10: print(stack); print()
        if x in visited:
            continue
        else:
            visited[x] = px
            if x == n:
                px = visited[x]
                while px != 0:
                    print(x, end='--')
                    while px + 1 == x and px != 0:
                        x = px
                        px = visited[x]
                    print(x, end=', ')

                    if px == 0: return lx
                    x = px
                    px = visited[px]
                print(x)
                return lx

            else:
                stack.append((x+1,x,lx+1))
                stack.append((num_of_digits(list(reversed(digits(x)))),x,lx+1))

import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    n = int(sys.stdin.readline())
    #nsteps = bf(n)
    nsteps2 = solve(n)
    print('Case #{}: {}'.format(icase,nsteps2))
    #if nsteps != nsteps2: print('WARNING');
    #print('Case #{}: {} {}'.format(icase,nsteps,nsteps2))
