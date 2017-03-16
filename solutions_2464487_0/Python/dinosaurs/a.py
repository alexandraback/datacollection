from math import sqrt

T = int(raw_input())

for case in range(1, T + 1):
    line = raw_input().split(' ')
    r = int(line[0])
    t = int(line[1])

    x = 0.25 * (-2 * r + 1) + 0.25 * sqrt(4 * r * r - 4 * r + 8 * t + 1)
    x = int(x)
    while 2 * x**2 - x + 2 * r * x <= t:
        x += 1
    while 2 * x**2 - x + 2 * r * x > t:
        x -= 1
    print 'Case #%d: %d' % (case, int(x))
