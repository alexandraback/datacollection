import math
square_palim = set([1])

#MAX = 1000
MAX = 100000000000000
for i in range(2, int(math.sqrt(MAX))+1):
    if str(i) == str(i)[::-1]:
        j = int(math.sqrt(i))
        if j*j == i and str(j) == str(j)[::-1]:
            square_palim.add(i)
        if str(i*i) == str(i*i)[::-1]:
            square_palim.add(i*i)

square_palim = list(square_palim)
square_palim.sort()
T = int(raw_input())
for tcase in range(T):
    a, b = map(int, raw_input().split())
    cnt = 0
    for i in square_palim:
        if i < a: continue
        if i > b: break
        cnt += 1
    print 'Case #%d: %d' % (tcase+1, cnt)
    
