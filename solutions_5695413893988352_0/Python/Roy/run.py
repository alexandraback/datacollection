lines = open("B-small-attempt1.in").readlines()

T = int(lines[0])

caseno = 1

def strsetchar(str, idx, val):
    s = list(str)
    s[idx] = val
    return "".join(s)
    
for line in lines[1:T+1]:
    line = line.lstrip().rstrip()
    
    C = (line.split(" ")[0])
    J = (line.split(" ")[1])
    
    l = len(C)
    
    ansC = ""
    ansJ = ""
    lastSolidC = -1
    lastSolidJ = -1
    reverse = False
    for i in range(0, l):
        if C[i] == "?" and J[i] == "?":
            if i > 0:
                dcp = lastSolidC
                djp = lastSolidJ
                if dcp < 0:
                    # no solid encountered yet, just use "0" until a solid is encountered
                    ansC = ansC + "0"
                    ansJ = ansJ + "0"
                else:
                    if dcp == djp:
                        ansC = ansC + "0"
                        ansJ = ansJ + "0"
                    if dcp < djp:
                        if reverse:
                            ansC = ansC + "0"
                            ansJ = ansJ + "9"
                        else:
                            ansC = ansC + "9"
                            ansJ = ansJ + "0"
                    if dcp > djp:
                        if reverse:
                            ansC = ansC + "9"
                            ansJ = ansJ + "0"
                        else:
                            ansC = ansC + "0"
                            ansJ = ansJ + "9"
            else:
                ansC = ansC + "0"
                ansJ = ansJ + "0"
        if C[i] == "?" and not J[i] == "?":
            ansC = ansC + J[i]
            ansJ = ansJ + J[i]
        if not C[i] == "?" and J[i] == "?":
            ansC = ansC + C[i]
            ansJ = ansJ + C[i]
        if not C[i] == "?" and not J[i] == "?":
            dcp = lastSolidC
            djp = lastSolidJ
            dc = int(C[i])
            dj = int(J[i])
            if dcp < 0 and i > 0:
                # first solid encountered
                # if abs difference in first solids is > 5
                absdiff = abs(dc - dj)
                if absdiff == 0:
                    pass
                elif absdiff > 5:
                    prevC = C[i-1]
                    prevJ = J[i-1]
                    # if prevC and prevJ both nonsolid
                    if prevC == '?' and prevJ == '?':
                        #if firstsolidc > firstsolidj
                        if dc > dj:
                            ansJ = strsetchar(ansJ, i-1, "1")
                        else:
                            ansC = strsetchar(ansC, i-1, "1")
                        reverse = not reverse
                    # if only one is nonsolid, and it's not 0
                    # adjust such that delta of prevC and prevJ is 1
                    """
                    elif not prevC == '?' and prevJ == '?' and prevC != '0':
                        # prevC is nonsolid
                        if dc > dj:
                            # prevJ should be > prevC and prevC is solid, so change J to be prevC + 1
                            pc = int(ansC[i-1])
                            ansJ = strsetchar(ansJ, i-1, str(pc + 1))
                        else:
                            # prevJ should be < prevC and prevC is solid, so change J to be prevC + 1
                    """        
                    
                else:
                    pass
            lastSolidC = C[i]
            lastSolidJ = J[i]
            ansC = ansC + C[i]
            ansJ = ansJ + J[i]
            
                    
                    
                    
    
    print 'Case #%s: %s %s' % (caseno, ansC, ansJ)
    
    caseno = caseno + 1
        
