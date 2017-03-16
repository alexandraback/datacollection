def Iterate( vmax, val ):
    Ret = [0]*(E+1);

    # After activity will have energy in range [R,E];
    for Enew in range(R, E+1):
        for Eold in range(E+1):
            dE = Eold-Enew+R;       # Removes issues from going negative in energy.
            if dE >= 0:
                dV = dE*val;
                Ret[Enew] = max(Ret[Enew], vmax[Eold]+dV);

    return Ret;
        
    


T = int(raw_input());
for q in range(T):
    [E, R, N] = map(int, raw_input().split());
    R = min(R, E);
    V = map(int, raw_input().split());

    t = 0;
    Vmax = [0]*(E+1);
    while (t < N):
        Vmax = Iterate(Vmax, V[t]);
        t += 1;

    print "Case #%d: %d" %(q+1, max(Vmax))

