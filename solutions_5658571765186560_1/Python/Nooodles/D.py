### Google code jam 2015
### Qualification round
### Problem D: Ominous Omino

def Answer(bit):
    if (bit == True):
        print "GABRIEL";
    else:
        print "RICHARD";

def Solve(x,r,c):
    if (r*c % x != 0) or (max(r,c) < x):
        return False;

    if (x <= 2):
        return True;
    if (x == 3):
        return min(r,c) >= 2;
    if (x == 4):
        return min(r,c) >= 3;
    if (x == 5):
        return min(r,c) >= 4;
    if (x == 6):
        return min(r,c) >= 4;

    return False;       ## A 7-omino and above can have holes ...

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    [X,R,C] = map(int, raw_input().split());
    Answer(Solve(X,R,C))
