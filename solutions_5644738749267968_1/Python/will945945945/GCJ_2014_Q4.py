F = open('/Users/poy/Downloads/D-large.in.txt')
A = F.read()
F.close()
A = A.split('\n')[1:-1]


def cheat(A,B):
    A = map(lambda x: (x,'N'),A)
    B = map(lambda x: (x,'K'),B)
    C = A+B
    C.sort(key = lambda x: x[0])
    D = map(lambda x: x[1],C)
    ans = 0
    def fcn(X):
        Temp = []
        for i in xrange(len(X)):
            if X[i] == 'K' and len(Temp) == 0:
                Temp.append(i)
            if X[i] == 'N' and len(Temp) == 1 and i > Temp[0]:
                Temp.append(i)
                break
        if len(Temp) == 2:
            X.pop(Temp[1])
            X.pop(Temp[0])
            return 1
        else:
            return 0
    while fcn(D):
        ans += 1
    return ans

def normal(A,B):
    A = map(lambda x: (x,'N'),A)
    B = map(lambda x: (x,'K'),B)
    C = A+B
    C.sort(key = lambda x: x[0])
    D = map(lambda x: x[1],C)
    ans = 0
    def fcn(X):
        Temp = []
        for i in xrange(len(X)):
            if X[i] == 'N' and len(Temp) == 0:
                Temp.append(i)
            if X[i] == 'K' and len(Temp) == 1 and i > Temp[0]:
                Temp.append(i)
                break
        if len(Temp) == 2:
            X.pop(Temp[1])
            X.pop(Temp[0])
            return 1
        else:
            return 0
    while fcn(D):
        ans += 1
    return ans

Ans = []

for i in xrange(len(A)/3):
    n = int(A[3*i])
    N = A[3*i+1].split(' ')
    K = A[3*i+2].split(' ')
    Ans.append( (cheat(N,K),n - normal(N,K)) )

E = open('/Users/poy/Desktop/output.txt','w')
for i in xrange(len(Ans)):
    E.write('Case #' + str(i+1) + ': ' + str(Ans[i][0]) + ' ' + str(Ans[i][1]) + '\n')
E.close()







        
