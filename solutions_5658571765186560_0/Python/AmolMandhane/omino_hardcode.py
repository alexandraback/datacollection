hardcoded = [
    [[1,1,1,1],
    [1,1,1,1],
    [1,1,1,1],
    [1,1,1,1]],

    [[0,1,0,1],
    [1,1,1,1],
    [0,1,0,1],
    [1,1,1,1]],

    [[0,0,0,0],
    [0,0,1,0],
    [0,1,1,1],
    [0,0,1,0]],

    [[0,0,0,0],
    [0,0,0,0],
    [0,0,0,1],
    [0,0,1,1]]
]

for T in xrange(input()):
    X, R, C = map(int, raw_input().split(" "))
    if hardcoded[X-1][R-1][C-1] == 1:
        print "Case #%d: GABRIEL" % (T+1,)
    else:
        print "Case #%d: RICHARD" % (T+1,)
