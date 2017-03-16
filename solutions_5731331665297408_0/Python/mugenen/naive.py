import sys
import collections
import random
import itertools

T = int(raw_input())
for t in xrange(1, T + 1):
    N, M = map(int, raw_input().split())
    code = []
    for i in xrange(N):
        code.append(input())
    neighbor = collections.defaultdict(list)
    for i in xrange(M):
        x, y = map(int, raw_input().split())
        neighbor[x - 1].append(y - 1)
        neighbor[y - 1].append(x - 1)
    result = '99999999'*10
    if N == 1 and M == 0:
        print "Case #{0}: {1}".format(t, code[0])
        continue
    for p in itertools.permutations(xrange(N)):
        cur = [p[0]]
        temp = str(code[cur[-1]])
        success = False
        for n in p[1:]:
            while cur:
#                print cur, n
                if n not in neighbor[cur[-1]]:
                    cur.pop()
                    continue
                else:
                    cur.append(n)
                    temp += str(code[cur[-1]])
                    if n == p[-1]:
                        success = True
                    break
        else:
            if success:
                result = min(temp, result)
    
    print "Case #{0}: {1}".format(t, result)
