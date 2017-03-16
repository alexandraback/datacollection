import sys

case_num = int(sys.stdin.readline().strip())

for i in range(0, case_num):
    r, t = [int(x) for x in sys.stdin.readline().split()]

    N_MAX = 2 * 10 ** 18
    left = 0
    right = N_MAX
    while left <= right:
        center = (left + right) / 2
        cost = 2 * center * (center + r - 1) + center
        if cost > t:
            right = center - 1
        else:
            left = center + 1

    print "Case #%d: %d" % (i + 1, right)
