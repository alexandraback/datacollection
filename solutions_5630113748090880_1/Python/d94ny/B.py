from collections import defaultdict
t = int(raw_input())

def missing(lines):
    d = {}
    for line in lines:
        for h in line:
            if h in d:
                d.pop(h, None)
            else:
                d[h] = True

    return sorted(d.keys())


for i in range(t):
    n = int(raw_input())
    lines = []

    for _ in range(2*n - 1):
        lines.append(map(int, raw_input().split(' ')))

    print "Case #{}:".format(i+1),
    print ' '.join(map(str, missing(lines)))


