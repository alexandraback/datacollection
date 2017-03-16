#!/usr/bin/env python3

import sys, os, re
import collections
import heapq
sys.setrecursionlimit(200)

def debug(x):
    print(x, file=sys.stderr) 


def flip(stack, pos):
    f = tuple(not x for x in stack[:pos+1][::-1])+stack[pos+1:]
    #debug("%s\nflipped on pos %d to\n%s" % (str(stack), pos, str(f)))
    return f

def invert(stack):
    f = tuple(not x for x in stack)
    return f
    
#@profile


def main():
    D = [x.strip() for x in sys.stdin.readlines()]
    N, D_raw = int(D[0]), D[1:]
    D = [[y == '+' for y in x] for x in D_raw]
    D = [tuple(x) for x in D]

    debug(N)
    debug(D)

    for numinput, d in enumerate(D, 1):
        #ans = solve_bfs(d)
        #ans = solve_recursive(d, True)
        ans = solve_count(d)
        print("Case #%d: %s" % (numinput, str(ans)))

def solve_count(d):
    count = 0
    for i in range(1, len(d)):
        if d[i-1] != d[i]:
            count += 1
    if not d[-1]:
        count += 1
    return count


def solve_recursive(d):
    debug("%s : %s" % (str(d), str(p)))
    if len(d) == 0:
        return 0
    sum = 0
    if d[-1]:
        sum += solve_recursive(d[:-1])
    else:
        sum += 1
        f = flip(d[:-1], len(d[:-1])) 
        if f[-1]:
            sum += solve_recursive(f)
        else:
            sum += 1
            r = []
            for j in range(len(d[:-1])):
                f = flip(d[:-1], j)
                #r.append(


    return sum

def solve_recursive_2(d, p):
    debug("%s : %s" % (str(d), str(p)))
    if len(d) == 1:
        if d[-1] == p:
            return 0
        else:
            return 1

    sum = 0
    f = d[:-1]
    p_new = d[-1] 
    if not (d[-1] == p):
        sum += 1
        #f = flip(f, len(f))
        #p_new = not p_new
    sum += solve_recursive(f, p_new )
    return sum


def solve_bfs(d):
        #BFS
        ans = ""
        considered = {}
        h = []
        heapq.heappush(h, (0, d))
        #queue = collections.deque([(d)])
        #queue_i = collections.deque([(0)])
        considered[d] = True 
        while(len(h) > 0 and ans == ""):
            #cand = queue.popleft()
            #flips = queue_i.popleft()
            flips, cand = heapq.heappop(h)
            if len(cand) == 0 or all(cand):
                ans = flips
                break

            if cand[-1]: #last pancake correct
                f = cand[:-1]
                heapq.heappush(h, (flips, f))
            else: #last pancake incorrect
                f = flip(cand, len(cand))
                if f[-1]: #new end correct
                    if f[:-1] in considered:
                        #debug("found cached tuple")
                        continue
                    considered[tuple(f[:-1])] = True
                    heapq.heappush(h, (flips + 1, f[:-1]))
                else: #do two flips
                    #for i in range(len(f)-1):
                    for i in range(1):
                        f = flip(flip(cand, i), len(cand))
                        if f[:-1] in considered:
                            #debug("found cached tuple")
                            continue
                        considered[tuple(f[:-1])] = True
                        heapq.heappush(h, (flips + 2, f[:-1]))

        return ans

   
if __name__ == '__main__':
    main()
