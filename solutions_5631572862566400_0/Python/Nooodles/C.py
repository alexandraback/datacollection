### Google code jam 2016
### Online round 1A
### 

import itertools;

F = [0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800];

def Try(sequence, N):
    if BFFi[sequence[0]] == sequence[1]:
        best = 0;
        for L in range(2, len(sequence)+1):
            test = sequence[:L];
            if works(test, L):
                best = L;
        return best;
    else:
        return 0;

def works(sequence, L):
    i = 0;
    while i < L:
        b1 = BFFi[sequence[i-1]];
        if ((b1 != sequence[i-2]) and (b1 != sequence[i])):
            return False;
        i += 1;
    return True;
    
Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    N = int(raw_input());
    BFFi = map(int, raw_input().split());
    for i in range(N):
        BFFi[i] -= 1;
    Ans = 0;

    A = itertools.permutations(range(N));
    for index in range(F[N]):
        Ans = max(Ans, Try(A.next(), N));
    print Ans

