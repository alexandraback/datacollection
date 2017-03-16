subsets = lambda x: [[y for j, y in enumerate(set(x)) if (i >> j) & 1] for i in range(2**len(set(x)))]

def do_it(numbers):
    seen = {}
    for ss in subsets(numbers):
        total = 0
        for n in ss:
            total += n
        if total in seen:
            return " ".join(map(str, ss)) + "\n" + " ".join(map(str, seen[total]))
        else:
            seen[total] = ss
    return "Impossible"

import sys
lines = sys.stdin.read().split("\n")[1:-1]
case_n = 0
for line in lines:
    case_n += 1
    numbers = map(int, line.split()[1:])
    print "Case #%i:\n%s" % (case_n, do_it(numbers))
