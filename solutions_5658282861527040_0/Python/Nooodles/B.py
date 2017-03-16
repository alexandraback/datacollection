def Solve(strings):
    Master = FindMap(strings[0]);
    #print Master,
    for s in strings:
        if FindMap(s) != Master:
            print "Fegla Won";
            return;

    Lengths = [];
    for s in strings:
        Lengths.append( FindLengths(s, Master) );
    
    #print Lengths, 

    FindMedianSum(Lengths);
    
    #print 'needs work';
    return;
    

def BruteSolve(a,b,k):
    Ans = 0;
    for i in range(a):
        for j in range(b):
            if i&j < k:
                Ans += 1;
    return Ans;

T = int(raw_input());
for q in range(T):
    print "Case #%d:" % (q+1),;

    [A,B,K] = map(int, raw_input().split());
    print BruteSolve(A,B,K);
        
