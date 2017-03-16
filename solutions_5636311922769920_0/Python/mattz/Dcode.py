import sys
import math

infile = open(sys.argv[1],'r')

T = infile.readline()
T = T.rstrip()

for index in range(int(T)):
    KCS = infile.readline().rstrip().split(' ')
    K = int(KCS[0])
    C = int(KCS[1])
    S = int(KCS[2])

    coefficients = range(K) + [K-1] * (S*C - K)
    
    if S*C < K:
        print 'Case #' + str(index+1) + ': IMPOSSIBLE'
    else:
        positions = []
        for m in range(int(math.ceil(float(K)/C))):
            cumulative_position = 0;
            for s in range(C):
                cumulative_position += min((m*C + s),K-1) * (K ** (C-1-s))
            # AAHHHHH OF COURSE I HAD AN OFF-BY-ONE ERROR
            positions.append(str(cumulative_position + 1))
        print 'Case #' + str(index+1) + ': ' + ' '.join(positions)
