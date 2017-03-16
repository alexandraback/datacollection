def Search(inp):
    [r,t] = inp
    # first ring of paint takes 2*r+1, then 2*r+5 etc
    N0 = 1;     N1 = t/(2*r+1)+1;
    while (N1 - N0 > 1):
        Nm = (N1+N0)/2;
        # can we paint ring #Nm?
        P0 = 2*r+1;
        Pm = P0 + 4*(Nm-1);
        if (Pm+P0)*(Nm+1) <= 2*t:
            N0 = Nm;
        else:
            N1 = Nm;

    P0 = 2*r+1
    if (P0+(N1-1)*4+P0)*(N1) <= 2*t:
        return N1;
    return N0


T = int(raw_input());
for q in range(T):
    print "Case #%d: %d" %(q+1, Search(map(int, raw_input().split())));

