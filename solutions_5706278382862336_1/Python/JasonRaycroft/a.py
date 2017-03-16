f = open("A-large.in", 'r')
g = open("A-large.out", 'w')
cases = f.readline()

def ispwr2(n):
    if n == 1:
        return False
    while n % 2 == 0:
        n = n / 2
        print n
    if n == 1:
        return True
    return False

casenr = 0
for case in f.readlines():
    casenr += 1
    g.write('Case #' + str(casenr) + ": ")
    num, den = map(int, case.split('/'))
    print num, den
    
    while num %2 == 0 and den %2 == 0:
        num = num / 2
        den = den / 2

    print num, den
    if den % num == 0:
        den = den / num
        num = num / num
        
    if ispwr2(den):
        print "possible", num, den
        i = 0
        while num < den:
            i = i + 1
            num = num * 2
        print i
        g.write(str(i) + '\n')
        
    else:
        print "impossible"
        g.write("impossible\n")
g.close()
