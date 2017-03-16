# -*- coding: utf-8 -*-
# python ProblemA.py < test1.in > A.small.out
# python ProblemA.py < A-small-attempt0.in > A.small.out
# =================================================================

result_out = ''

def solve(data):
    S = map(int, list(data.split()[1]))
    count = s_low = 0
    for k, s in enumerate(S):
        diff = 0 if s_low >= k else k - s_low
        count += diff
        s_low += (S[k] + diff)
    return count

case_num = int(raw_input())

for idx in range(case_num):
    data = raw_input()
    case_out = solve(data)
    result_out += 'Case #%d: %s\n' % (idx+1, case_out)
print result_out