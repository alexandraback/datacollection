sol = {(1, 1): [1], (1, 2): [1, 2], (1, 3): [1], (1, 4): [1, 2], (2, 2): [1, 2], (2, 3): [1, 2, 3], (2, 4): [1, 2], (3, 3): [1, 3], (3, 4): [1, 2, 3, 4], (4, 4): [1, 2, 4]}
for c in xrange(input()):
    X, R, C = map(int, raw_input().split())
    if R > C: R, C = C, R            
    print "Case #" + str(c + 1) + ":",
    print ["GABRIEL", "RICHARD"][X not in sol[(R, C)]]
