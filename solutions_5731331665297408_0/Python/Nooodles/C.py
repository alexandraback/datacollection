F = [1,1,2,6,24,120,720,5040,40320];

def Lexographic(N, index):
    TODO = [];
    for i in range(N):
        TODO.append(i+1);
    RET = [];

    for i in range(N-1,-1,-1):
        RET.append(TODO.pop(index/F[i]));
        index = index%F[i];
    return RET;


def BruteSolve(zips, flights, ordering):
    n = len(zips);
    Pattern = "";
    for index in ordering:
        Pattern += str(zips[index-1]);
    Usable = [ordering[0]];
    next = 1;
    while (next < len(ordering)):
        if (len(Usable) == 0):
            return [False, ""];

        nextCity = ordering[next];
        if ([Usable[-1], nextCity] in flights) or ([nextCity, Usable[-1]] in flights):
            Usable.append(nextCity);
            next += 1;
        else:
            Usable.pop(-1);

    return [True, Pattern];

T = int(raw_input());
for q in range(T):
    print "Case #%d:" % (q+1),;
    Ans = "Moo";
    
    [N, M] = map(int, raw_input().split());
    ZipCodes = [];
    Flights = [];
    for i in range(N):
        ZipCodes.append(int(raw_input()));
    for i in range(M):
        Flights.append(map(int, raw_input().split()));

    for i in range(F[N]):
#        print i,
        [canDo, ans] = BruteSolve(ZipCodes, Flights, Lexographic(N, i));
        if (canDo):
#            print ans;
            if ans < Ans:
                Ans = ans;

    print Ans;
        
