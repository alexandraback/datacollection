#! /usr/bin/env python3

T = int(input())

for case_nr in range(T):
    N = int(input())

    if N == 0:
        print("Case #{}: INSOMNIA".format(case_nr+1))
    else:
        sought = set(range(10))
        sum = 0
        count = 0
        while sought:
            count += 1
            sum += N
            digits = [int(d) for d in str(sum)]
            sought = sought.difference(digits)
        print("Case #{}: {}".format(case_nr+1, sum))

