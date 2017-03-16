#-*-coding:utf-8-*-

import os, sys, math

fh = open(sys.argv[1])
T = int(fh.readline())
for t in range(T):
    vals = [int(x) for x in fh.readline().strip().split(' ')]
    N = vals[0]
    scores = sorted(vals[1:])
    m0 = scores[0]
    m1 = scores[1]
    s = sum(scores)
    ssum = 0.0
    #required_score = m0 + (m1 - m0 + s) / 2.0 # m0 + p * s
    #required_score = m1
    resolved = False
    #required_score = m1
    #print(scores)
    #print('total {0}'.format(s))
    for i in range(1, N):
        s_ = i * (scores[i] - scores[i-1])
        #print(i, scores[i], ssum, s_, ssum + s_)
        if ssum + s_ >= s:
            required_score = scores[i-1] + (s - ssum) / i#(s - ssum) / i#s_
            #print(scores[i], s - ssum, (s - ssum) / i, required_score)
            #required_score = scores[i-1] * p + (scores[i] - scores[i-1])
            resolved = True
            break
        ssum += s_
        pass
    if not resolved:
        #print('not resolved')
        required_score = scores[-1] + float(s - ssum) / N
        pass
    #m0 + p * s > m1 + (1-p) * s
    #p(s + s) > m1 - m0 + s
    #p > (m1 - m0 + s) / 2s
    #
    #print('cutoff {0}'.format(required_score))
    sys.stdout.write('Case #{0}:'.format(t + 1))
    for score in vals[1:]:
        if score > required_score:
            p = 0.0
        else:
            p = (required_score - score) / s
            pass
        sys.stdout.write(' {0:.6f}'.format(p * 100))
        pass
    sys.stdout.write('\n')
    pass
    
