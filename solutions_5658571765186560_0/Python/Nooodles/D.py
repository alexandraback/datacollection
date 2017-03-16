### Google code jam 2015
### Qualification round
### Problem D: Ominous Omino

def Answer(bit):
    if (bit == True):
        print "GABRIEL";
    else:
        print "RICHARD";

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    [X,R,C] = map(int, raw_input().split());

    if (X == 1):
        Answer(True);
    if (X == 2):
        Answer(R*C % 2 == 0);
    if (X == 3):
        Answer(R*C in [6,9,12]);
    if (X == 4):
        Answer( R*C in [12,16]);
