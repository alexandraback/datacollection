def subsets(l):
    """Returns all subsets of l"""
    if l == []: yield []
    else:
        l = list(l)
        a = l.pop()
        for s in subsets(l):
            yield s
        for s in subsets(l):
            yield s + [a]

def scores(l):
    l = [(sum(s), s) for s in subsets(l)]
    l.sort()
    return l

def out(l):
    l.sort()
    return " ".join(str(i) for i in l);

################################################################
def solve():
    N = [int(x) for x in input.readline().split(' ')][1:]
    n = len(N)
    d = dict()
    i = 0
    for lst in subsets(N):
        score = sum(lst)
        if d.get(score) is None:
            d[score] = list(lst)
        else:
            return "\n" + out(lst) + "\n" + out(d[score])
    return "\nImpossible"

    S1,S2 = scores(N[:n/2]), scores(N[n/2:])
    S2.reverse()
    t,i,j,i_next,j_next = -1,-1,-1,0,0
    while (i+j <= n-2):
        if S1[i_next]+S2[j_next] == t:
            return out(S1[i]+S2[j]) + "\n" + out(S1[i_next]+S2[j_next])
        if (i_next == n/2-1):
            i,j,i_next,j_next = i_next,j_next,i_next,j_next+1
        elif (j_next == n/2-1):
            i,j,i_next,j_next = i_next,j_next,i_next+1,j_next
        elif (S1[i_next+1]+S2[j_next] <=
              S1[i_next]+S2[j_next+1]):
            return "XXXX"
        
    return len(S1), len(S2)
################################################################

from datetime import datetime
time_start = datetime.today()
def now(): return datetime.today() - time_start 

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in','.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in','.out'), 'w')
n = int(input.readline())

for i in range(1,n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
