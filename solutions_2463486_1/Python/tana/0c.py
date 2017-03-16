def getLine(filename):
    inputFile = open(filename, 'r')
    for line in inputFile:
        yield line
    inputFile.close()

inputFilename = 'C-large-1.in'
outputFilename = 'C-large-1.txt'

tokenIterator = getLine(inputFilename)
def get():return tokenIterator.next()
def getint(): return int(get())
outputFile = open(outputFilename, 'w')

# END PRE-PROCESSING

x = [1,2,3,11,22]

def palin(p):
    return str(p) == str(p)[::-1]

def yud(dim, pol, sai):
    m = (10**(dim-1)+1)*pol
    if sai != 0:
        m += sai * 10**((dim-len(str(sai)))/2)
    return m

for d in xrange(3,15):
    x.append(yud(d,1,0))
    lx = len(x)
    for i in xrange(lx):
        l = len(str(x[i]))
        if l > d-2:
            break
        if (d-l) & 1 == 0:
            w = yud(d,1,x[i])
            if palin(w*w):
                x.append(w)
            
    x.append(yud(d,2,0))
    if d & 1 == 1:
        x.append(yud(d,2,1))

# END PRE-PROCESSING, FOR REAL

caseNum = getint()
for case in range(caseNum):

    (a,b) = [int(v) for v in get().split()]
    
    def cnt(z):
        global x
        best = -1
        left = 0
        right = len(x)-1
        while left <= right:
            mid = (left+right)/2
            if x[mid]**2 <= z:
                best = mid
                left = mid+1
            else:
                right = mid-1
        return best+1
                
    ans = cnt(b) - cnt(a-1)
    
    output = "Case #"+str(case+1)+": "+str(ans)
    outputFile.write(output+"\n")

# BEGIN POST-PROCESSING
outputFile.close()

