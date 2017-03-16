
F = open('/Users/poy/Downloads/B-large.in.txt')
A = F.read()
F.close()
A = A.split('\n')[1:-1]
A = map(lambda x: map(float,x.split(' ')),A)

def g(n):
    return round(n*(10**7))/10**7

def fcn(C,F,X):

    G = 2
    n = 0
    ans = 100000000

    def farm(n):
        if n > 0:
            X = []
            for i in xrange(n):
                X.append(G + F*i)
            X = map(lambda x: 1/x , X)
            X = reduce(lambda x,y: x+y, X)
            return C * X
        else:
            return 0
    
    Ans = []
    farm = 0
    while Ans == []:
        
        t = farm + X/(G + F*n)

        n += 1
        farm += C/(G + F*(n-1))
        if t < ans:
            ans = t
        else:
            Ans.append(ans)
    return g(Ans[0])
        
Ans = []

for i in xrange(len(A)):
    print i
    Ans.append(  fcn(  A[i][0] , A[i][1] , A[i][2]  )  )
    

E = open('/Users/poy/Desktop/output.txt','w')

for i in xrange(len(Ans)):
    E.write('Case #' + str(i+1) + ': ' + str(Ans[i]) + '\n')

E.close()












