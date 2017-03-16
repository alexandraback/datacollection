def solve(Smax, L):
    total = sum(L)
    i = 0
    res = 0 
    for level, num in enumerate(L):
        if i < level: 
            res += (level-i)
            i += (level-i)
        i += num
    return res
        


import sys
fin = sys.stdin
#fin = open('input.txt', 'r')
#fout = open('output.txt', 'w')

T = int(fin.readline().strip())
for t in range(T):
    Smax, L = fin.readline().split()
    Smax = int(Smax)
    L = map(int, list(L))
    res = "%s" % solve(Smax, L)
    s = "Case #%d: %s\n" % (t+1, res)
    print s,



