# google code jam 2012 round 1b

# equal sums

import itertools

def numlist(s, n, v):
    answer =""        
    for i in range(n):
        if (1<<i & v):
            answer += " " + str(s[i])
    return answer[1:] + "\n"


f = open("c:\\users\\James\\Downloads\\C-small-attempt0.in", "r")
#f = open("equal.in","r")
fout= open("equal.out", "w")

t = int(f.readline())

for t1 in xrange(t):
    # m chars already typed out of n total
    s = map(int, f.readline().split() )
    n = s[0]
    s = s[1:]

    sums = {}
    fout.write("Case #%d:\n" % (t1+1))
    found = False
    for v in xrange(2**n):
        total = 0
        for i in range(n):
            if (1<<i & v):
                total += s[i]
        if total in sums:
            found = True
            break
        else:
            sums[total] = v

    if found:
        print numlist(s, n, v),
        fout.write(numlist(s, n, v))
        print numlist(s, n, sums[total]),
        fout.write(numlist(s, n, sums[total]))
    else:
        fout.write("Impossible\n")

fout.close()
        
