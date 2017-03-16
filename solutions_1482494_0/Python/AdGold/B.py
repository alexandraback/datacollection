
f = open('B-small-attempt0.in')
out = open('B.out', 'w')

nt = int(f.readline())

for t in xrange(nt):
    count = stars = 0
    n = int(f.readline())
    levels = []
    for i in xrange(n):
        levels.append(tuple(reversed(map(int,f.readline().split()))))
    levels.sort(reverse = True)
    while levels:
        if stars >= levels[-1][0]:
            #print stars,
            stars += 2-(len(levels[-1])>=3)
            #print stars
            #print (len(levels[-1])>=3),
            lev = levels.pop()
            #print lev
            count += 1
        else:
            for i,l in enumerate(levels):
                if stars >= l[1]:
                    levels[i] = l+(1,)
                    stars += 1
                    count += 1
             #       print l,'bla'
                    break
            else:
                count = 'Too Bad'
                break
    out.write('Case #%d: %s\n' % (t+1, str(count)))

out.close()
    
