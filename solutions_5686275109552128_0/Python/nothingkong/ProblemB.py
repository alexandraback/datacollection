# -*- coding: utf-8 -*-
# python ProblemB.py < test2.in > B.small.out
# python ProblemB.py < A-small-attempt0.in > B.small.out
# =================================================================

result_out = ''

import bisect
from collections import Counter

def solve(case_data):
    P = Counter(map(lambda x: int(x), case_data.split()))
    Q_number = sorted(P.keys())
    result_out = max(Q_number)
    MAX_number = result_out
    for i in xrange(2, MAX_number+1):
        pos = bisect.bisect_right(Q_number, i)
        time = i
        for j in xrange(pos, len(Q_number)):
            number = Q_number[j]
            time += (number - 1) / i * P[number]
        result_out = min(result_out, time)
    return result_out

case_num = int(raw_input())

for idx in range(case_num):
    raw_input()
    data = raw_input()
    case_out = solve(data)
    result_out += 'Case #%d: %s\n' % (idx+1, case_out)
print result_out