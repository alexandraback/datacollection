T = int(raw_input())

def dec_to_bin(x):
    return int(bin(x)[2:])

for t in xrange(T):
    A,B,K = map(int, raw_input().split())

    print "Case #%d:" % (t + 1),

    if (K>=min(A,B)):
        print A*B
    else:
        count = 0
        for i in xrange(A):
            for j in xrange(B):
                res = i & j
                if (res < K):
                    count = count + 1
        print count