### Google code jam 2016
### Online round 1A
### 

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    N = int(raw_input());
    Data = [0]*3000;
    for i in range(2*N-1):
        row = map(int, raw_input().split());
        for j in row:
            Data[j] += 1;

    for k in range(len(Data)):
        if Data[k]%2 == 1:
            print k,

    print;
    
