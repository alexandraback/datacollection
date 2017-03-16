lines = open("A-small-attempt0 (1).in").readlines()

T = int(lines[0])

caseno = 1

def extractString(origStr, stringToExtract):
    newStr = origStr
    for c in stringToExtract:
        idx = newStr.find(c)
        # remove first instance
        newStr = newStr.replace(c, "", 1)
        
    return newStr
        
    
for line in lines[1:T+1]:
    line = line.lstrip().rstrip()
    
    
    S = len(line)
    digits = []
    
    currstr = line
    while currstr.find("Z") >= 0:
        digits.append(0)
        currstr = extractString(currstr, "ZERO")
    while currstr.find("W") >= 0:
        digits.append(2)
        currstr = extractString(currstr, "TWO")
    while currstr.find("X") >= 0:
        digits.append(6)
        currstr = extractString(currstr, "SIX")
        
    while currstr.find("G") >= 0:
        digits.append(8)
        currstr = extractString(currstr, "EIGHT")
    # any H after removing 8s are 3s
    while currstr.find("H") >= 0:
        digits.append(3)
        currstr = extractString(currstr, "THREE")
        
    while currstr.find("U") >= 0:
        digits.append(4)
        currstr = extractString(currstr, "FOUR")
    # any F after removing 4s are 5s
    while currstr.find("F") >= 0:
        digits.append(5)
        currstr = extractString(currstr, "FIVE")
    # any V after removing 5s are 7s
    while currstr.find("V") >= 0:
        digits.append(7)
        currstr = extractString(currstr, "SEVEN")
        
    # any remaining Os are ONEs
    while currstr.find("O") >= 0:
        digits.append(1)
        currstr = extractString(currstr, "ONE")
    
    # any remaining Ns are NINEs
    while currstr.find("N") >= 0:
        digits.append(9)
        currstr = extractString(currstr, "NINE")
        
    
    sd = sorted(digits)
    
    ans = ""
    for d in sd:
        ans = ans + str(d)
    
    print 'Case #%s: %s' % (caseno, ans)            
    
    caseno = caseno + 1

#print extractString("OZONETOWER", "ZERO")