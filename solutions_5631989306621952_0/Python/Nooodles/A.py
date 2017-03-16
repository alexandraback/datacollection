### Google code jam 2016
### Online round 1A
### 

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    S = raw_input().split()[0];

    Ans = '';
    for c in S:
        if (c + Ans < Ans + c):
            Ans = Ans + c;
        else:
            Ans = c + Ans;
    print Ans;
        
