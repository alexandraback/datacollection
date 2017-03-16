### Google code jam 2016
### Online round 1C
### Problem C

def Solve(J, P, S, K):
    Set = [J,P,S];
    K = min(K, S);
        
    if K == S:
        PrintAll(J, P, S);
        return; 

    GenerateSolution(J, P, S, K);
    

def GenerateSolution(J, P, S, K):
    print J*P*K;
    for j in range(J):
        for p in range(P):
            for s in range(K):
                print (j+1), (p+j)%P + 1, (p+j+s)%S+1
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

    Solve(J, P, S, K);
