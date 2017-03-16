# recycled numbers

def nchoose2(n):
    return n*(n-1)/2

def recycled(a,b):
    seen = set()
    count = 0
    n = len(str(a))  # guaranteed to be same as len(b)
    for x in xrange(a,b+1):
        if x not in seen:
            s = str(x)
            xcount = 0
            for i in range(0,n):
                y = int( s[i:] + s[:i] )
                if a<=y<=b and y not in seen:
                    seen.add(y)
                    xcount +=1
            count += nchoose2(xcount)
    return count
                
f = open("c-small-attempt1.in", "r")
outf = open("c-small.out", "w")

t = int( f.readline() )
for t1 in range(t):
    a,b = map(int, f.readline().split() )
    score = recycled(a,b)
    print a,b, score
    outf.write("Case #" + str(t1+1)+": " + str(score) +"\n")
outf.close()
