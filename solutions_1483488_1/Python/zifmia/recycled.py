# recycled numbers

nchoose2 = [ n*(n-1)/2 for n in range(0,8)]
##def nchoose2(n):
##    return n*(n-1)/2

def recycled(a,b):
    seen = set()
    count = 0
    n = len(str(a))  # guaranteed to be same as len(b)
    for x in xrange(a,b+1):
        if x not in seen:
            s = str(x)
            xcount = 1
            seen.add(x)
            for i in range(1,n):
                y = int( s[i:] + s[:i] )
                if a<=y<=b and y not in seen:
                    seen.add(y)
                    xcount +=1
            count += nchoose2[xcount]
    return count

import time
start = time.clock()

f = open("c:\\users\\james\\downloads\\c-large (1).in", "r")
outf = open("c-large.out", "w")

t = int( f.readline() )
for t1 in range(t):
    a,b = map(int, f.readline().split() )
    score = recycled(a,b)
    print a,b, score
    outf.write("Case #" + str(t1+1)+": " + str(score) +"\n")
outf.close()

print time.clock() - start
