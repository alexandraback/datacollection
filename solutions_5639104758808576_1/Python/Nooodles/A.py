### Google code jam 2015
### Qualification round
### Problem A: Standing Ovation

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    Input = raw_input().split();
    Smax = int(Input[0]);
    Data = [];
    for c in Input[1]:
        Data.append(int(c));

    Needed = [1-Data[0]];
    for i in range(1, len(Data)):
        Needed.append( Needed[-1] + 1 - Data[i] );

    print max(max(Needed),0);
