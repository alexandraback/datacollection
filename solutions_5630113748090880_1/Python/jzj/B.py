from collections import defaultdict

T = int(raw_input())


def solve():
    n = int(raw_input())
    d = defaultdict(lambda: 0)
    for line_no in xrange(2 * n - 1):
        for item in map(int, raw_input().split()):
            d[item] += 1
    answer = []
    for k, v in d.iteritems():
        if v % 2 == 1:
            answer.append(k)
    answer.sort()
    return ' '.join(map(str, answer))

for case_no in xrange(1, T + 1):
    print "Case #%d: %s" % (case_no, str(solve()))
