def Solve( P ):
    Is3 = False;        Is5 = False;        K = len(P);
    New = [];           ANS = [];
    for e in P:
        New.append(e);
        if e%3 == 0:
            Is3 = True;
        if e%5 == 0:
            Is5 = True;

    print New;
    New.sort();
    while New[0] == 1:
        New.pop(0);
        K -= 1
    print New;
    
    if Is3:
        ANS.append(3);
        for i in range(K):
           if New[i]%3 == 0:
               New[i] /= 3 ;
    if Is5:
        ANS.append(5);
        for i in range(K):
           if New[i]%5 == 0:
               New[i] /= 5;

    print Is3, Is5, New;

    return 




def Brute1(a,b,c):
    VAL = [1, a, b, c, a*b, a*c, b*c, a*b*c];
    VAL.sort();
    for i in range(6,-1,-1):
        if VAL[i] == VAL[i+1]:
            VAL.pop(i);
    return VAL;
               
                
T = int(raw_input());
#R = 100;        N = 3;      M = 5;      K = 7;
Data = [];
for q in range(T):
    print 'Case #1:';
    [R, N, M, K] = map(int, raw_input().split());

    PAIR = [];      PROD = [];
    for a in range(2,6):
      for b in range(a,6):
        for c in range(b,6):
          PAIR += [str(a)+str(b)+str(c)];
          PROD.append( Brute1(a,b,c) );
#          print PAIR[-1], PROD[-1]

#    for a in range(20):
#        print a, PROD[a];
#    print 
        
    for case in range(R):
        Inp = map(int, raw_input().split())
#        print Inp
        Hit = [];
        for i in range(20):
           Good = True;
           for e in Inp:
              if e not in PROD[i]:
#                print 'badness', i, e, PAIR[i], PROD[i]
                Good = False;
           if Good:
              Hit.append(i);

        print PAIR[Hit[0]]
            
#        Match( map(int, raw_input().split()) );

