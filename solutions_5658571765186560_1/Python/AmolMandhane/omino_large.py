import numpy

game = numpy.zeros((6, 20, 20))

game[0, :, :] = 1
game[1, 1:20:2, :] = game[1, :, 1:20:2] = 1

game[2, 2:20:3, :] = game[2, :, 2:20:3] = 1
game[2, :1, :] = game[2, :, :1] = 0

game[3, 3:20:4, :] = game[3, :, 3:20:4] = 1
game[3, :2, :] = game[3, :, :2] = 0

game[4, 4:20:5, :] = game[4, :, 4:20:5] = 1
game[4, :3, :] = game[4, :, :3] = 0

game[5, 5:20:6, :] = game[5, :, 5:20:6] = 1
game[5, :3, :] = game[5, :, :3] = 0

for T in xrange(input()):
    X, R, C = map(int, raw_input().split(" "))
    if X >= 7:
        print "Case #%d: RICHARD" % (T+1,)
    elif game[X-1][R-1][C-1] == 1:
        print "Case #%d: GABRIEL" % (T+1,)
    else:
        print "Case #%d: RICHARD" % (T+1,)
