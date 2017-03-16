lines = open("B-small-attempt0.in").readlines()

T = int(lines[0])

caseno = 1

def flip(currstr, n):
    # flip from 1 to n (0 to n-1)
    #print "flip at %s" % (n)
    nextstr = currstr[0:n]
    nextstr = nextstr[::-1]
    nextstr = nextstr.replace("+", "*")
    nextstr = nextstr.replace("-", "+")
    nextstr = nextstr.replace("*", "-")
    # add everything starting from c
    nextstr = nextstr + currstr[n:]
    return nextstr

for line in lines[1:T+1]:
    line = line.lstrip().rstrip()
    #print "-----"
    currstr = line
    flipcount = 0
    minusfound = True
    while minusfound:
        minusfound = False
        nextstr = ''
        l = len(line)
        n = 0
        #print "Case #%s: %s" % (caseno, currstr)
        for c in currstr:
            if c == '-':
                if minusfound == False:
                    minusfound = True
            if currstr[0] == '+':
                # starts with plus, look for first minus
                if minusfound:
                    flipcount = flipcount + 1
                    nextstr = flip(currstr, n)
                    break
            else:
                if minusfound and c == '+':
                    flipcount = flipcount + 1
                    nextstr = flip(currstr, n)
                    break
                if minusfound and n == l-1:
                    flipcount = flipcount + 1
                    nextstr = flip(currstr, n+1)
                    break
            nextstr = nextstr + c
            n = n + 1
        currstr = nextstr
        #print "Case #%s: %s" % (caseno, nextstr)
    print "Case #%s: %s" % (caseno, flipcount)
    caseno = caseno + 1