# code jam qualifier 2013 problem C

# fair and square

# brute force - only feasible for small input

def isPalindrome(n):
    sn = str(n)
    return sn == sn[::-1]

def precalc(nmax):
    global fs
    fs = [0]*(nmax+1)
    i = 1
    while i*i<=nmax:
        if isPalindrome(i) and isPalindrome(i*i):
            fs[i*i] = 1
        i += 1
    # now make array a cumulative total

    for i in range(1, nmax+1):
        fs[i] += fs[i-1]


precalc(1000)

fin = open("C-small-0.in", "r")
fout = open("C-small-0.out", "w")

t = int(fin.readline())
for testCase in xrange(t):
    a,b = map(int, fin.readline().split())
    
    answer = fs[b] - fs[a-1]
    
    fout.write( "Case #" + str(testCase+1) + ": " + str(answer) + "\n")

fout.close()
