from math import sqrt

def merge(ev, od):
    return ''.join(item for tup in zip(ev,od) for item in tup)

def Next(N, J):
    coins = []
    # generate jamcoins with 6 | sum a_i and 21 | sum (-)^i a_i
    # automatically divisble by 3, 2, 3, 2, 7, 2, 3, 2, 3, unless sum a_i divisible by 30 (then 5 replaces 7)
    # so let sum a_i = 6 and sum (-)^i a_i = 0. (easy to obtain more jamcoins with different conditions)
    # as first and last digits are determined need to put 2 ones in the even slots and 2 ones in the odd slots
    # there are 15 choose 2 possibilities for either, and 11025 > 500
    aux  = []
    n = (N-2)/2-1 # 32 -> 14
    for i in xrange(n):
        for j in xrange(n-i):
            aux.append(i*'0' + '1' + j*'0' + '1'+ (n-1-i-j)*'0')
    for a in aux:
        for b in aux[:5]: #can replace 5 by n
            coins.append('1'+merge(a,b)+'1')
    return (coins[:J], [3, 2, 3, 2, 7, 2, 3, 2, 3]) #okay for J < (n choose 2)**2

input = open(r'./C-large.in')

input.readline()
N, J = (int(n) for n in input.readline().strip().split())
#N, J = 32, 500
sol = Next(N, J)

tofile = True
if tofile:
    with open(r'./outputC-L.txt', 'w') as output:
        output.write('Case #1: \n')
        for s in sol[0]:
            output.write(s)
            x = ' ' + ' '.join(str(j) for j in sol[1])+'\n'
            output.write(x)
                        
else:
    for s in sol[0][:20]:
        print s,
        print sol[1]
