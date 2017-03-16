# code jam qualifier 2013 problem C

# fair and square

# minor rethink for medium-size problem

def isPalindrome(n):
    sn = str(n)
    return sn == sn[::-1]

fsNumbers = []

def precalc(nmax):
    """ find all FS numbers with sqrt up to nmax """
    for i in xrange(1, nmax+1):
        if isPalindrome(i) and isPalindrome(i*i):
            fsNumbers.append(i*i)

def fairSquareNumbers(a,b):
    """ Return the number of fair-and-square numbers between a and b """

    count = 0
    for fs in fsNumbers:
        if a <= fs:
            if fs <= b:
                count += 1
            else:
                break
    return count

precalc(10**7)

print len(fsNumbers)

fin = open("C-large1-0.in", "r")
fout = open("C-large1-0.out", "w")

t = int(fin.readline())
for testCase in xrange(t):
    a,b = map(int, fin.readline().split())
    
    answer = fairSquareNumbers(a, b)
    
    fout.write( "Case #" + str(testCase+1) + ": " + str(answer) + "\n")

fout.close()
