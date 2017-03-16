import sys


f = open(sys.argv[1])

T = int(f.readline())

def output(case, result):
    print "Case #%s: %s" % (case + 1, result)

case = 0
while case < T:
    N = int(f.readline())
    count = {}
    for n in range((2 * N) - 1):
        line = f.readline()
        values = map(int, line.split())
        for v in values:
            if v in count:
                count[v] = count[v] + 1 
            else:
                count[v] = 1

    odd_values = []
    for key, value in count.iteritems():
        if value % 2 != 0:
            odd_values.append(key)

    odd_values.sort()
    odd_values = map(str, odd_values)
    output(case, " ".join(odd_values).strip())
    case += 1
