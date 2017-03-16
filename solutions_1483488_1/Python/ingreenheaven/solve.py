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
    (A, B) = map(int, raw_input().split())
    skip = [0]*(B-A + 1)
    total = 0
    for x in xrange(A, B):

        if skip[x - A] > 0:
            continue

        s = str(x)
        PSET = set()
        PSET.add(x)
        for j in xrange(1, len(s)):
            if s[j] == '0':
                continue
            r = s[j:] + s[:j]
            y = int(r)
            if y >= A and y <= B:
                PSET.add(y)

        if len(PSET) < 2:
            continue

        P = []
        P.extend(PSET)
        P.sort()
#        print P
        l = len(P)
        for j in xrange(l):
            index = P[j] - A
            skip[index] = 1
        total += ((l-1)*l) / 2
#        print total
#    print sum(count), count

    res = 'Case #' + str(i) + ': ' + str(total)
    print res
    out.write(res + '\n')

# No change after this

out.close()
