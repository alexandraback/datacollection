#test

def getnthsquare( x, y, maxx):
    return y+1 #should just be the num needed down the side, ie 1 for y=0 and 1 more for each up
def getpwr(ndiamonds):
    n = 0
    while( n*(2*n-1) <= ndiamonds):
        n+=1
    n-=1
    nrem = ndiamonds - n*(2*n-1)
    return 2*n-1, 2*(n-1), nrem,n

def comb(N,i):
    total = 1
    for num in range(N-i+1, N+1): #gives N!/N-i!
        total*=num
    for num in range(1, i+1):
        total/=num
    #print N, "choose", i, "is", total
    return total
        
def calculateprob( N, X):
    #print 'calc prob of N x', N,X
    if X > N:
        return 0.0
    total = 0
    for i in range(X, N+1): #sigma sum over i=x to i=n
        total+=comb(N, i)
    numDiv = 0
    while total > 2**100:
        total/=2
        numDiv+=1
    return float(total) / 2**(N - numDiv)
    #return total / (2**N)
    
def getP( ndiamonds, x, y):
    print "ndiamonds,x,y", ndiamonds, x,y
    if ndiamonds==0:
        return 0.0
    numInBase, maxx, remaining,n = getpwr(ndiamonds)
    print "numinbase, maxx, remaining", numInBase, maxx, remaining
    ##maxx is rightmost x, note it's always even ie stagger thing
    sumxy = abs(x) + abs(y)
    if sumxy <= maxx: #within triangle
        print "in triangle"
        return 1.0
    if sumxy > maxx + 2: ##no way to reach it
        print "unreachable"
        return 0.0
    if x==0: #means at the very top, impossible to get
        print "top, can't get"
        return 0.0
    ##somewhere in between
    X = getnthsquare( abs(x), y, maxx) #return what pos, ie min fall squares: 1 for bottom,
    minPerSide = remaining - 2*n
    if minPerSide >= X:
        print  "guaranteed by fall"
        return 1.0
    temp = calculateprob( remaining, X)
    print "temp", temp
    return temp

data = [line.strip() for line in open("input.txt")]
output = []
for item in data[1:]:
    line = [int(token) for token in item.split()]
    output.append(getP(line[0],line[1],line[2]))

f = open("output.txt", 'w')
for i in range(len(output)):
    f.write("Case #"+str(i+1)+": "+str(output[i])+"\n")
f.close()
    
