#!/usr/bin/python

f = open('D-small-attempt7.in','r');
out = open('D-small-attempt7.out','w');

T = int(f.readline().strip())
for t in range(T):
    X,R,C = [int(x) for x in f.readline().strip().split(' ')]
    #print "x {}, r {}, c {}".format(X,R,C)

    mx = max(R,C)
    mn = min (R,C)
    richard_wins = False

    if (R*C) % X != 0:
        richard_wins = True

    if X >=7:
        richard_wins = True # can make a donut
    elif X > mx:
        # maybe win by bisection, assume so
        richard_wins = True
    elif X == mx:
        # maybe can bisect in minor dimension
        if X >= 4 and X >= mn + (mn -1):
            richard_wins = True
    else:
        #can't win by bisection, try squaring
        if X >= 4 and mn < 2:
            richard_wins = True
        if X >= 9 and mn < 3:
            richard_wins = True
        if X >= 16 and mn < 4:
            richard_wins = True

    max_angle = 1+((X-1) // 2)

    if max_angle > mn:
        richard_wins = True

    line =  "Case #{}: {}".format(t+1, "RICHARD" if richard_wins else "GABRIEL")
    print line
    out.write(line+"\n")

f.close()
out.close()


