lines = open("C-small-attempt0.in").readlines()

T = int(lines[0])

caseno = 1
    
def printJamcoin(length):
    pass
    
def isJamcoin(candidate):
    baseNs = []
    for i in range(2, 11):
        baseN = int(candidate, i)
        # if one of the bases has no divisor, is false
        divisor = getDivisor(baseN)
        if divisor < 0:
            return False
        # print "%s :: %s / %s = %s" % (i, baseN, divisor, baseN/divisor)
        baseNs.append(str(divisor))
        
    return baseNs

def getDivisor(n):
    i = 2
    limit = int((n ** 0.5) + 1)
    # optimization
    if limit > 32000:
        limit = 32000
    while i < limit:
        if n%i==0:
            return i
        i = i + 1
    return -1
    
def checkJamcoin(candidate):
    ret = isJamcoin(candidate)
    if ret == False:
        return 0
    print '%s %s' % (candidate, ' '.join(ret))
    return 1
    
def genJamcoins(length, limit):
    max = int(2 ** length-2)
    count = 0
    format = '{0:0%sb}' % (length-2)
    i = 0
    while i < max and count < limit:
        if count >= limit:
            #print "break limit"
            break
        candidate = '1' + format.format(i) + '1'
        #print "Trying %s" % (candidate)
        i = i + 1
        count = count + checkJamcoin(candidate)
        #print count


for line in lines[1:T+1]:
    line = line.lstrip().rstrip()
    N = int(line.split(" ")[0])
    J = int(line.split(" ")[1])
    print 'Case #%s:' % (caseno)
    genJamcoins(N, J)
    caseno = caseno + 1
        
