import sys

T = int(sys.stdin.readline())

for n in range(1, T+1):
    N = int(sys.stdin.readline())

    curr = 0
    digits = set()
    count = 0
    for i in range(0, 1000000):
        curr += N
        count += 1
        digits.update(set(str(curr)))
        if len(digits) == 10:
            break

    if len(digits) == 10:
        print "Case #{}: {}".format(n, curr)
    else:
        print "Case #{}: {}".format(n, 'INSOMNIA')

