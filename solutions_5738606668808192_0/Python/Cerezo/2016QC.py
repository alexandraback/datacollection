from math import sqrt

def first_factor(n):
    if not n % 2:
        return 2
    sqn = int((sqrt(n)-1)/2)
    for i in range(3, sqn+1):
        if not n % i:
            return i
    return 0

def Next(N, J):
    coins = []
    count = 0
    for i in xrange(2**8,2**8+250): #heuristic
        strjc = '1' + (N-8-3)*'0'+str(bin(i))[2:] + '1'
        #print strjc, 
        primeflag = False
        factors = []
        for b in range(2, 11):
            jc = int(strjc, b)
            k= first_factor(jc)
            if k == 0:
                primeflag = True
                break
            factors.append(k)
        #print factors
        if not primeflag:
            count += 1
            print 'found number', count, 'at try', i-2**8
            coins.append((strjc, factors))
            if count == J:
                break
    return coins


input = open(r'./C-small-attempt0.in')

T = int(input.readline())

#sol = []

for i in xrange(T):
    N,J = (int(n) for n in input.readline().strip().split())
    #N, J = 16, 50
    sol = Next(N, J)

tofile = True
if tofile:
    with open(r'./outputC.txt', 'w') as output:
        for i in range(T):
            output.write('Case #%s: \n' % (i+1))
            for s in sol:
                output.write(s[0])
                x = ' ' + ' '.join(str(j) for j in s[1])+'\n'
                output.write(x)
                        
else:
    for s in sol:
        print s[0],
        for i in s[1]:
            print i,
        print ' '
