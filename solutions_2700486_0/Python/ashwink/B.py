import sys
import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    (N, X, Y) = [int(x) for x in f.readline().split()]

    # wlog, X >= 0 and Y >= 0
    X = abs(X)
    Y = abs(Y)

    if (X + Y) % 2 != 0:
        # the sum of X and Y must be even
        # for a diamond to possibly land there
        answer = 0.0
    else:
        # with N diamonds, figure out how far out the pyramid
        # must already exist
        phase = -1
        while N >= 4 * (phase + 1) + 1:
            phase += 1
            N -= 4 * phase + 1

        if X + Y <= 2 * phase:
            answer = 1.0
        else:
            # move on to next phase of pyramid
            phase += 1

            if X + Y > 2 * phase:
                answer = 0.0
            
#            print "(%d, %d)" % (X, Y)
            # K is the number of diamonds I need to go right
            # N is the remaining number of diamonds at our disposal
            K = 2 * phase - X + 1
#            print "K: %d" % K
            if K > N:
                answer = 0.0
            else:
                if N > 2 * phase:
                    K -= (N - 2 * phase)
                    N -= (N - 2 * phase) * 2
                if K <= 0:
                    answer = 1.0
                else:
#                    print "phase: %d" % phase
#                    print "diamonds remaining: %d" % N
                    # we need *at least* K diamonds to go right
                    answer = 0.0
                    for k in range(K, N + 1):
                        answer += nCr(N, k) * ((0.5) ** N)
#                        print answer
                
    print "Case #%d: %0.6f" % (case + 1, answer)
    sys.stdout.flush()
