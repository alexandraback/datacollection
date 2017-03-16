def scores(n):
    if n == 0:
        return [0, False]
    base = int(n / 3)
    diff = n - base * 3
    if diff == 0:
        #return [base, base, base]
        return [base, True]
    elif diff == 1:
        #return [base, base, base+1]
        return [base+1, False]
    else:
        #return [base, base+1, base+1]
        return [base+1, True]

import sys
lines = sys.stdin.read().split("\n")[1:-1]
case_count = 0
for line in lines:
    case_count += 1
    arr = line.split()
    arr = map(int, arr)
    n, s, p = arr[:3]
    vals = arr[3:]
    count = 0
    for val in vals:
        base, can_surprise = scores(val)
        if base >= p:
            count += 1
        elif base + 1 >= p and can_surprise and s > 0:
            count += 1
            s -= 1
    print "Case #%i: %i" % (case_count, count)
