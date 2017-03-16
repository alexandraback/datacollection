import sys
from collections import defaultdict

cache = []
def do_it(c, j, a, b, i):
    #print "do_it", a, b, i
    if i == len(c):
        cache.append((abs(int(a) - int(b)), int(a), int(b)))
        return
    if c[i] != "?" and j[i] != "?":
        do_it(c, j, a+c[i], b+j[i], i+1)
    if c[i] == "?" and j[i] == "?":
        do_it(c, j, a+"0", b+"9", i+1)
        do_it(c, j, a+"9", b+"0", i+1)
        do_it(c, j, a+"0", b+"0", i+1)
        do_it(c, j, a+"9", b+"9", i+1)
        do_it(c, j, a+"0", b+"1", i+1)
        do_it(c, j, a+"1", b+"0", i+1)
        do_it(c, j, a+"1", b+"1", i+1)
    if c[i] == "?" and j[i] != "?":
        x = int(j[i])
        for o in [x, (10+x-1) % 10, (10+x+1) % 10]:
            do_it(c, j, a+str(o), b+j[i], i+1)
        do_it(c, j, a+"9", b+j[i], i+1)
        do_it(c, j, a+"0", b+j[i], i+1)
    if c[i] != "?" and j[i] == "?":
        x = int(c[i])
        for o in [x, (10+x-1) % 10, (10+x+1) % 10]:
            do_it(c, j, a+c[i], b+str(o), i+1)
        do_it(c, j, a+c[i], b+c[i], i+1)
        do_it(c, j, a+c[i], b+c[i], i+1)
        do_it(c, j, a+c[i], b+"0", i+1)
        do_it(c, j, a+c[i], b+"9", i+1)
    
    
T = int(sys.stdin.readline())
case = 1
for case in range(1, T+1):
    cache = []
    c,j = sys.stdin.readline().strip().split()
    do_it(c,j,"", "", 0)
    w = min(cache)
    print "Case #{0}:".format(case), str(w[1]).zfill(len(c)), str(w[2]).zfill(len(c)) 
    #case += 1
        
