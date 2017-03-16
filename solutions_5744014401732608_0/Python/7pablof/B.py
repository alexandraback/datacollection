import math
import itertools

f = open('B-small-attempt3.in')
##f = open('B-large.in')
f2 = open('file.txt','w')
T = f.readline()
i = 0
for l in f:
    i += 1
    B, M = [int(x) for x in l.split()]
    print(str(B) + ' ' + str(M))
    print(2**(B-2))
    if (2**(B-2) < M):
        print("Case #" + str(i) + ": IMPOSSIBLE",file=f2)
        continue
    else:
        print("Case #" + str(i) + ": POSSIBLE",file=f2)
    r = set()
    num = 0
    for x in reversed(range(B-1)):
        for y in itertools.combinations(range(1, B-1), x):
            print(y)
            if (len(y) > 0):
                r.add((0, y[0]))
                r.add((y[len(y)-1], B-1))
            else:
                r.add((0, B-1))
            for z in range(len(y) - 1):
                r.add((y[z], y[z+1]))
            num += 1
            if num == M:
                break
        if num == M:
            break
    for j in range(B):
        for k in range(B):
            if((j, k) in r):
                print('1', end="", file=f2)
            else:
                print('0', end="", file=f2)
        print('', file=f2)
f.close()
f2.close()
