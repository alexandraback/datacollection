import sys

def getTotalDiamondsForLayer(layer):
    total = 0
    for x in xrange(0, layer+1, 2):
        total += (2 * x) + 1
    return total

T = int(sys.stdin.readline())

for i in xrange(T):
    N, X, Y = sys.stdin.readline().strip().split()
    N = int(N)
    X = abs(int(X))
    Y = int(Y)

    # in range?
    layer = X + Y

    if layer == 0:
        print "Case #%d: 1.0" % (i+1)
        continue

    prevLayer = layer - 2

    neededDiamonds = getTotalDiamondsForLayer(prevLayer) + 1
    maxProb = neededDiamonds + (2 * layer)

    #print layer, neededDiamonds, maxProb

    if N < neededDiamonds:
        print "Case #%d: 0.0" % (i+1)
        continue

    if N >= maxProb:
        print "Case #%d: 1.0" % (i+1)
        continue

    # neededDiamonds <= N < maxProb
    # 1 <= NN
    # NN = number of diamonds dropped in the layer
    NN = N - neededDiamonds + 1

    #print "NN: %d" % NN

    count = 0
    #print "looking at %d combos" % (1 << NN)
    for j in xrange(1 << NN):
        k = j
        c = 0
        while k:
            k &= k-1
            c += 1
        #print "c is %d" % c
        if c > layer:
            c = layer
        if c > Y:
            count += 1

    prob = count / float(1 << NN)

    print "Case #%d: %f" % (i+1, prob)

