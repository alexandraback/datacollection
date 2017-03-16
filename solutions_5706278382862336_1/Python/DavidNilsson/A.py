from collections import deque
f = open('./A-large.in')
#f = open('./test.in')
nbrs = deque([k for k in f.read().split()])
f.close()

def hasnext():
    return len(nbrs) > 0

def read():
    return nbrs.popleft()

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)

f = open('out.txt', 'w')
cases = int(read())
for cc in range(1, cases+1):
    N = read().split('/')
    P, Q = int(N[0]), int(N[1])    
    P, Q = P//gcd(P, Q), Q//gcd(P, Q)
    
    ans = "impossible"
    Qp = Q
    while (Qp % 2) == 0:
        Qp = Qp//2
    if Qp == 1:
        ans = 0
        while P < Q:
            P = 2*P
            ans += 1
        
    
    f.write("Case #" + str(cc) + ": " + str(ans) + "\n")
    
f.close()

#f = open('out.txt')
#for line in f:
#    print(line)
#f.close()