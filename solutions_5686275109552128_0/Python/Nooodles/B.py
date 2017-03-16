### Google code jam 2015
### Qualification round
### Problem B: Infinite house of pancakes

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    D = int(raw_input());
    P = map(int, raw_input().split());
    Ans = max(P);

    for eats in range(1, max(P)):
        splits = 0;
        for plate in P:
            if (plate > eats):
                splits += (plate - 1)/eats;

        Ans = min(Ans, splits + eats);

    print Ans
