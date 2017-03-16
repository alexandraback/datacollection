infile = open("A-small-attempt0.in", "rU")
outfile = open("A-small-attempt0.out", "w")

linenum = 0
case = 1

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
          
##        num_substrings = (length*(length+1))/2
##
##        total = 0
##        start = 0
##        x = 0 # Length substring of 1s
##        y = 0 # Length substring without n consecutive 1s
##        
##        for i in cons:
##            if i == 1:
##                x += 1
##            else:
##                x = 0
##
##            if x == n:
##                print name, n, y
##                
##                total += (y*(y+1))/2
##                x = n-1
##                y = n-1
##
##            else:
##                y += 1
##
##        print name, n, y
##        total += (y*(y+1))/2
##            
##        outfile.write("Case #%d: %d\n" % (case, num_substrings - total))

        total = 0

        for i in xrange(length):
            for j in xrange(i, length):
                if "".join(cons[i:(j+1)]).find("1"*n) != -1:
                    total += 1

        outfile.write("Case #%d: %d\n" % (case, total))

        case += 1    
    linenum += 1

outfile.close()
