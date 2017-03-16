################################################################
def solve():
    N = int(input.readline())
    naomi = [float(x) for x in input.readline().split(' ')]
    ken = [float(x) for x in input.readline().split(' ')]
    naomi.sort()
    ken.sort()
    merged = ([(naomi[i], 'naomi') for i in range(N)] +
              [(ken[i], 'ken') for i in range(N)])
    merged.sort()
    ken = 0
    deceit = N
    for _, person in merged:
        if person == 'ken':
            ken += 1
        elif ken == 0:
            deceit -= 1
        else:
            ken -= 1

    merged.reverse()
    ken = 0
    real = 0
    for _, person in merged:
        if person == 'ken':
            ken += 1
        elif ken == 0:
            real += 1
        else:
            ken -= 1
    return "%d %d" % (deceit, real)
################################################################

from datetime import datetime
time_start = datetime.today()


def now():
    return datetime.today() - time_start

import sys
infilename = sys.argv[1]
outfilename = infilename.replace('.in', '.out')

input = open(sys.argv[1], 'r')
output = open(sys.argv[1].replace('.in', '.out'), 'w')
n = int(input.readline())

for i in range(1, n+1):
    result = solve()
    print "Case #%d: %s \t %s" % (i, result, now())
    output.write("Case #%d: %s\n" % (i, result))
    output.flush()
