import sys,math,re,copy

def bit(k, b):
    return int(k/pow(2,b) % 2)

def maxbit(k):
    return int(math.log(k)/ math.log(2))+ 1


def bitands(a,b,m):
    return sum([bit(a,i) * bit(b,i) * pow(2,i) for i in xrange(m+1)])

def solve(line):
    A,B,K = [int(s) for s in line.split(' ')]
    maxK = maxbit(K)
    maxA = maxbit(A)
    maxB = maxbit(B)
    m = max(maxK,maxA,maxB)
    ret = 0
    for i in xrange(A):
        for j in xrange(B):
            if bitands(i,j,m) < K:
                ret += 1
    return ret
                
problems=[]
for i,line in enumerate(sys.stdin):
    if i == 0:
        totalN=int(line.strip('\r\t\n '))
    else:
        print 'Case #%s: %s'%(i+1,solve(line.strip('\r\t\n ')))
        
    
