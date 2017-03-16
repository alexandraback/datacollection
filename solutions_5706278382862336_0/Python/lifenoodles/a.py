import sys
import fractions

sys.stdin = open('in')
sys.stdout = open('out', 'w')


def is_power_2(x):
    if x == 0:
        return False
    while x % 2 == 0:
        x //= 2
    return x == 1


def count_powers(x):
    assert x != 0
    count = 0
    while x % 2 == 0:
        x //= 2
        count += 1
    return count


def count_dist(a, b):
    count = 1
    while a <= b:
        a += a
        count += 1
    return count

cases = int(raw_input())
for case in xrange(cases):
    n, d = map(int, raw_input().split('/'))
    g = fractions.gcd(n, d)
    n, d = n // g, d // g
    if not is_power_2(d):
        print('Case #{}: impossible'.format(case + 1))
        continue
    if n * 2 >= d:
        ans = 1
    elif n == 1:
        ans = count_powers(d)
    else:
        ans = count_dist(n, d // 2)
    print('Case #{}: {}'.format(case + 1, ans))
