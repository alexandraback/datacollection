def awins(A,B, hint=-1):
    X = list(A)
    Y = list(B)
    wins = False;
    for i in range(len(X)):
        if wins:
            if X[i]=='?': X[i] = '0'         
            if Y[i]=='?': Y[i] = '9' 
        else:
            if X[i]!='?' and Y[i]!='?':
                if X[i] < Y[i]:
                    return (2**100,0,0)
                if X[i] > Y[i]:
                    wins = True
                continue

            if i == hint:
                if X[i] == '?' and Y[i] == '?': X[i], Y[i] = '1', '0'
                if X[i] == '?' and Y[i] != '9': X[i] = str(int(Y[i])+1)
                if Y[i] == '?' and X[i] != '0': Y[i] = str(int(X[i])-1)
                if X[i]!='?' and Y[i]!='?': wins = True
                    

            if X[i] == '?' and Y[i] == '?': X[i],Y[i] = '0', '0'
            if X[i] == '?': X[i] = Y[i]
            if Y[i] == '?': Y[i] = X[i]

    X = (''.join(X))
    Y = (''.join(Y))
    assert(X>=Y)
    return (int(X)-int(Y), X, Y)


        

def bwins(A,B, hint=-1):
    X = awins(B,A, hint)
    return (X[0], X[2], X[1])


def solve():
    A, B = input().split()
    best = min(awins(A,B),bwins(A,B))
    for i in range(len(A)):
        best = min(best, min(awins(A,B,i), bwins(A,B,i)))
        
    print(best[1], best[2])

T = int(input())
for i in range(T):
    print('Case #%s: ' % (i+1), end='')
    solve()
