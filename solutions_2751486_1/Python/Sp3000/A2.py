infile = open("A-large.in", "rU")
outfile = open("A-large.out", "w")

linenum = 0
case = 1

def f(n, k):
    # Number of substrings of n 1s containing at most k 1s

    if n >= k:
        return k*(n+1) - (k*(k+1))/2

    else:
        return (n*(n+1))/2

for line in infile:
    if linenum != 0:
        line = line.strip().split(" ")
        name = line[0]
        n = int(line[1])

        cons = []
        for letter in name:
            if letter in ["a", "e", "i", "o", "u"]:
                cons.append(str(0))

            else:
                cons.append(str(1))

        length = len(name)
          
        num_substrings = (length*(length+1))/2

        total = 0
        start = 0
        x = 0 # Length substring of 1s
        y = 0 # Length substring without n consecutive 1s

        xlist = []
        ylist = []
        
        for i in cons:
            if i == "1":
                x += 1
            else:
                if x >= n:
                    xlist.append(x)        
                x = 0

            if x == n:
                if y != 0:
                    ylist.append(y)
                    
                y = n-1
            elif x < n:
                y += 1

        if x >= n:
            xlist.append(x)

        if y != 0:
            ylist.append(y)

        for a in ylist:
            total += (a*(a+1))/2

        #print name, total

        for b in xlist:
##            if b >= 2*(n-1):
##                total += f(b, n-1) - n*(n-1) # n(n-1) = (n-1)((n-1) + 1)/2
##
##            else:
##                o = 2*(n-1) - b # overlap
##                total += f(b, n-1) - n*(n-1) + f(o, n-1)

            total += f(b-2, n-1) - 2*f(n-2, n-1)

        #print name, total
            
        outfile.write("Case #%d: %d\n" % (case, num_substrings - total))

        case += 1    
    linenum += 1

outfile.close()
