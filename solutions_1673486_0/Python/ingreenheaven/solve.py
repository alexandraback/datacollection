import sys

args = sys.argv

if len(args) < 2:
    print 'small or large?'
    exit()

inp = args[1]

out = open(inp + '_OUT', 'w')

# No change before this

T = input()

for i in xrange(1, T+1):
    A, B = map(int, raw_input().split())
    P = map(float, raw_input().split())
    best = B + 2
    prob = 1
    for j in xrange(A-1, -1, -1):
        #delete j chars
        prob *= P[A-j-1]
        keys = prob * (2*j + B - A + 1) + (1-prob) * (2*j + 2*B - A + 2)
        if keys < best:
            best = keys
    res = 'Case #' + str(i) + ': ' + str(best)
    print res
    out.write(res + '\n')

# No change after this

out.close()
