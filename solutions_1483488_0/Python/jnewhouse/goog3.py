def length(n):
    return len(str(n))
def rotate(n,l):
    return 10**(l-1)*(n%10) + n/10
def count(n,b,l):
    L =[]
    current = n
    for x in range(l):
        current = rotate(current,l)
        if n< current and current <=b and current not in L:
            L+=[current]
    return len(L)
def solve(a,b):
    total = 0
    l = length(a)
    for x in xrange(a,b):
        total+=count(x,b,l)
    return total
def solve2(a,b):
    L = [0]*(b+1)
    l = length(a)
    total = 0
    for x in xrange(a,b+1):
        if L[x]==0:
            count = 1
            current = 10**(l-1)*(x%10) + x/10
            #print current
            while current !=x:
                if current <=b and a<=current:
                    count+=1
                    L[current]=1
                current = 10**(l-1)*(current%10) + current/10
            total+=(count *(count-1))/2
    return total
T = int(raw_input())
for t in range(T):
    A,B = [int(x) for x in raw_input().split()]
    print "Case #"+str(t+1)+":",solve2(A,B)
    
    
