import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    moves = ""
    (X, Y) = [int(i) for i in f.readline().split()]
    (x, y) = (0, 0)

    while x != X or y != Y:
        if x < X:       # go to the right
            moves += "WE"
            x += 1
        elif x > X:     # go to the left
            moves += "EW"
            x -= 1
        
        if y < Y:       # go up
            moves += "SN"
            y += 1
        elif y > Y:
            moves += "NS"
            y -= 1
    
    print "Case #%d: %s" % (case + 1, moves)
    sys.stdout.flush()
