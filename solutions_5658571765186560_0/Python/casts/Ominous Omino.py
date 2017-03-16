infile  = open("D-small-attempt0.in", "r")
outfile = open("D-small-attempt0.out","w")
cases = int(infile.readline().strip())
for o in range(1,cases+1):
    X, R, C = map(int, infile.readline().strip().split())
    ans = True
    if X >= 7:
        ans = False
    elif X > R and X > C:
        ans = False
    elif R * C % X != 0:
        ans = False
    elif (X + 1) // 2 > min(R, C):
        ans = False
    elif X in (1, 2, 3):
        ans = True
    elif X == 4:
        ans = min(R, C) > 2
    elif X == 5:
        ans = not(min(R, C) == 3 and max(R, C) == 5)
    elif X == 6:
        ans = min(R, C) > 3  
    _x = 'GABRIEL' if ans else 'RICHARD'
    outfile.write("Case #%s: %s\r\n" % (o,_x))
infile.close()
outfile.close()