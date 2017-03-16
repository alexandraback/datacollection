FILE = "P2b"
try:
    inFile = open(FILE+".txt")
except:
    pass

def read():
    try:
        return inFile.readline().strip()
    except:
        return raw_input().strip()

    
nCr = [[0]*1500 for z in range(1500)]
for n in xrange(1500):
    nCr[n][n] = nCr[n][0] = 1
for n in xrange(1,150):
    for r in xrange(1,n):
        nCr[n][r] = nCr[n-1][r-1] + nCr[n-1][r]

out = open("P2.out","w")
cases = int(read())
for case in xrange(cases):
    z,n,h = map(int,read().split())
    ans = 0
    
    if z == 0:
        ans = 0
    elif z == 1:
        ans = 1
    else:
        step = 50
        base = float(2**step)
        for i in xrange(h,n+1):
            ans += nCr[n][i]
        exp = 0
        while exp+step < n:
            ans /= base
            exp += step
        ans /= float(2**(n-exp))
    
    print "Case #%i: %f" %(case+1,ans)
    out.write("Case #%i: %f\n" %(case+1,ans))
    