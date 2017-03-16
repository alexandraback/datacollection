
fin = open ("b.in" , "r");
fout = open ("b.out", "w");
for T in range (int (fin.readline ())) :
    w = list (map (int, fin.readline ().split (' ')));
    n, s, p = w[0], w[1], w[2];
    f = [[-1e18] * (s + 5) for i in range (n + 2)];
    f[0][0] = 0;
    for i in range (1, n + 1) :
        t = w[i + 2];
        upper = (t + 4) // 3;
        lower = (t + 2) // 3;
        for j in range (s + 1) :
            if j == 0 or t < 2 or t > 28 :
                f[i][j] = f[i - 1][j] + int (lower >= p);
            else :
                f[i][j] = max (f[i - 1][j] + int (lower >= p), f[i - 1][j - 1] + int (upper >= p));

    print ('Case #%d: %d' % (T + 1, f[n][s]), file = fout);
    print (f);
fin.close ();
fout.close ();
