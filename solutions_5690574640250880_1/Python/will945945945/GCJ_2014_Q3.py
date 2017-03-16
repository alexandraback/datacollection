

F = open('/Users/poy/Downloads/C-large.in.txt')
A = F.read()
F.close()
A = A.split('\n')[1:-1]
A = map(lambda x: map(int,x.split(' ')),A)

Ans = []

def g(A):
    A = reduce(lambda a,b: a+'\n' + b ,map(lambda x: reduce(lambda z,y: z+y,x),A))
    return A
def fcn(R,C,M):
    A = [['.' for i in xrange(C)] for i in xrange(R)]
    A[0][0] = 'c'
    def row_change(n):
        for i in xrange(len(A[n])):
            A[n][i] = '*'
    def column_change(n):
        for i in xrange(len(A)):
            A[i][n] = '*'
    #######################################
    if R > 3 and C > 3:
        if R*C-M >= 9:
            while M != 0:
                if R > C :
                    if M >= C:
                        row_change(R-1)
                        R -= 1
                        M -= C
                    elif M == C-1:
                        for i in xrange(M-1):
                            A[R-1][C-1-i] = '*'
                        A[R-2][C-1] = '*'
                        M = 0
                    else:
                        for i in xrange(M):
                            A[R-1][C-1-i] = '*'
                        M = 0                   
                elif R < C :
                    if M >= R:
                        column_change(C-1)
                        C -= 1
                        M -= R
                    elif M == R-1:
                        for i in xrange(M-1):
                            A[R-1-i][C-1] = '*'
                        A[R-1][C-2] = '*'
                        M = 0
                    else:
                        for i in xrange(M):
                            A[R-1-i][C-1] = '*'
                        M = 0                   
                else:
                    if M >= C:
                        row_change(R-1)
                        R -= 1
                        M -= C
                    elif M == C-1:
                        for i in xrange(M-1):
                            A[R-1][C-1-i] = '*'
                        A[R-2][C-1] = '*'
                        M = 0
                    else:
                        for i in xrange(M):
                            A[R-1][C-1-i] = '*'
                        M = 0
            return g(A)
        elif R*C-M == 8:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(3):
                    A[i][j] = '.'
            A[2][0] = '.'
            A[2][1] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 6:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(3):
                for j in xrange(2):
                    A[i][j] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 4:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(2):
                    A[i][j] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 1:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            A[0][0] = 'c'
            return g(A)
    #####################################
    elif R == 3 and C >= 3:
        if R*C-M >= 9:
            while M != 0:
                if R < C :
                    if M >= R:
                        column_change(C-1)
                        C -= 1
                        M -= R
                    elif M == R-1:
                        for i in xrange(M-1):
                            A[R-1-i][C-1] = '*'
                        A[R-1][C-2] = '*'
                        M = 0
                    else:
                        for i in xrange(M):
                            A[R-1-i][C-1] = '*'
                        M = 0
            return g(A)
        elif R*C-M == 8:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(3):
                    A[i][j] = '.'
            A[2][0] = '.'
            A[2][1] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 6:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(3):
                    A[i][j] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 4:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(2):
                    A[i][j] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 1:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            A[0][0] = 'c'
            return g(A)
    ######################################
    elif R >= 3 and C== 3:
        if R*C-M >= 9:
            while M != 0:
                if R > C :
                    if M >= C:
                        row_change(R-1)
                        R -= 1
                        M -= C
                    elif M == C-1:
                        for i in xrange(M-1):
                            A[R-1][C-1-i] = '*'
                        A[R-2][C-1] = '*'
                        M = 0
                    else:
                        for i in xrange(M):
                            A[R-1][C-1-i] = '*'
                        M = 0
            return g(A)
        elif R*C-M == 8:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(3):
                    A[i][j] = '.'
            A[2][0] = '.'
            A[2][1] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 6:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(3):
                for j in xrange(2):
                    A[i][j] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 4:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            for i in xrange(2):
                for j in xrange(2):
                    A[i][j] = '.'
            A[0][0] = 'c'
            return g(A)
        elif R*C-M == 1:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            A[0][0] = 'c'
            return g(A)
            
    ######################################
    elif R == 2 and C >= 2:
        if R*C-M >= 4:
            if M%2 == 0:
                m = M/2
                for i in xrange(m):
                    column_change(C-1-i)
                return g(A)
        elif R*C-M == 1:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            A[0][0] = 'c'
            return g(A)
    ######################################
    elif R >= 2 and C == 2:
        if R*C-M >=4:
            if M%2 == 0:
                m = M/2
                for i in xrange(m):
                    row_change(R-1-i)
                return g(A)
        elif R*C-M == 1:
            A = [['*' for i in xrange(C)] for i in xrange(R)]
            A[0][0] = 'c'
            return g(A)
    ######################################
    elif R*C-M >= 1 and R ==1:
        for i in xrange(M):
            column_change(C-1-i)
        return g(A)
    ######################################
    elif R*C-M >= 1 and C ==1:
        for i in xrange(M):
            row_change(R-1-i)
        return g(A)
    ######################################

    return 'Impossible'
    
for i in xrange(len(A)):
    Ans.append(fcn( A[i][0] , A[i][1] , A[i][2]))
    

E = open('/Users/poy/Desktop/output.txt','w')
for i in xrange(len(Ans)):
    E.write('Case #'+str(i+1)+':\n'+Ans[i]+'\n')
E.close()
    

    
    
















        
        
        
        
        
