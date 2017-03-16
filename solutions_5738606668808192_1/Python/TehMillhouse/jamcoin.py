#! /usr/bin/env python3

print('Case #1:')
input()
N, J = [int(i) for i in input().split()]
templ = (1 << (N-1)) + 1
lim = 1 << (N-2)
output = 0
for i in range(lim):
    cur = format(templ + (i << 1), 'b')
    divisors = [int(cur)] # dirty hack
    for div in range(3, 700, 2):
        if int(cur, len(divisors)+1) % div:
            continue
        divisors.append(div)
        if len(divisors) == 10:
            print(' '.join([str(i) for i in divisors]))
            output += 1
            break
    i += 1
    if output == J:
        break



