import sys

def digits(n):
    retval = set()
    while n > 0:
        retval.add(n % 10)
        n = n // 10
    return retval

next(sys.stdin)
case = 0
for s in sys.stdin:
    case += 1
    n = int(s.strip())

    if n == 0:
        print('Case #{}: INSOMNIA'.format(case))
        continue

    seen = set()
    acc = n
    while len(seen) < 10:
        seen.update(digits(acc))
        acc += n

    print('Case #{}: {}'.format(case, acc - n))
