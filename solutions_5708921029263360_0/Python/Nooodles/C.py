### Google code jam 2016
### Online round 1C
### Problem B

def Solve(B, M):
    Bchoose2 = (B*(B-1))/2;
    for i in range(1,2**Bchoose2):
        A = bin(i)[2:];
        A = '0'*(Bchoose2 - len(A)) + A;
        A = A[::-1]

        bridges = [];
        for i in range(Bchoose2):
            if A[i] == '1':
                bridges.append(i);

        if (Solutions(B, bridges, M)):
            return;
    print "IMPOSSIBLE";


def Bash(J, P, S, K):
    Set = [J,P,S];
    K = min(K, S);

    if K == S:
        PrintAll(J, P, S);
        return;

    print J*P*K;
    
    if (J == P == 1):
        for k in range(K):
            print '1 1', k+1
        return
    
    if (J == 1 and P == 2):
        if K == 1:
            print '1 1 1'
            print '1 2 2'
        if K == 2:
            print '1 1 1';
            print '1 1 2'
            print '1 2 1';
            print '1 2 2';
        return;
    
    if (J == 1 and P == 3):
        if K == 1:
            print '1 1 1'
            print '1 2 2'
            print '1 3 3'
        if K == 2:
            print '1 1 1'
            print '1 1 2'
            print '1 2 2'
            print '1 2 3'
            print '1 3 1'
            print '1 3 3'
        return;
            
    if (J == P == 2):
        if K == 1:
            print '1 1 1'
            print '1 2 2';
            print '2 1 2';
            print '2 2 1';
        if K == 2:
            print '1 1 1'
            print '1 1 2'
            print '1 2 1'
            print '1 2 2'
            
            print '2 1 1'
            print '2 1 2'
            print '2 2 1'
            print '2 2 2'
        return;

    if (Set == [2,3,3]):
        if K == 1:
            print '1 1 1'
            print '1 2 2';
            print '1 3 3';
            print '2 1 2';
            print '2 2 3';            
            print '2 3 1';
        if K == 2:
            print '1 1 1'
            print '1 1 2';
            print '1 2 1';
            print '1 2 3';
            print '1 3 2';            
            print '1 3 3';
            
            print '2 1 1';
            print '2 1 2';
            print '2 2 1';
            print '2 2 3';
            print '2 3 2';            
            print '2 3 3';           
            
    if (Set == [3,3,3]):
        if K == 1:
            print '1 1 1'
            print '1 2 2';
            print '1 3 3';
            
            print '2 1 2';
            print '2 2 3';            
            print '2 3 1';
            
            print '3 1 3';            
            print '3 2 1';
            print '3 3 2';            
        if K == 2:
            print '1 1 1'
            print '1 1 2';
            print '1 2 1';
            print '1 2 3';
            print '1 3 2';            
            print '1 3 3';
            
            print '2 1 2'
            print '2 1 3';
            print '2 2 2';
            print '2 2 1';
            print '2 3 3';            
            print '2 3 1';

            print '3 1 3'
            print '3 1 1';
            print '3 2 3';
            print '3 2 2';
            print '3 3 1';
            print '3 3 2';
    return;

def PrintAll(A, B, C):
    print A*B*C
    for a in range(1, A+1):
        for b in range(1, B+1):
            for c in range(1, C+1):
                print a, b, c
    return;                

  
Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),
    [J, P, S, K] = map(int, raw_input().split());

    Bash(J, P, S, K);
