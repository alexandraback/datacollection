import sys


MAX_PAL_SQUARE = 10 ** 14
MAX_SQUARE = 10 ** 7


def pal(num):
    n = num;
    rev = 0;
    while (num > 0):
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    if n == rev:
        return True
    else:
        return False


fair_and_square = []
for n in range(1, MAX_SQUARE + 1):
    if pal(n) and pal(n * n):
        fair_and_square.append(n * n)


f = open(sys.argv[1], 'r')
T = int(f.readline())
for i in range(T):
    case = int(i) + 1
    A, B = map(int, f.readline().strip().split(' '))
    count = 0
    for fns in fair_and_square:
        if fns >= A and fns <= B:
            count += 1
        if fns > B:
            break
    print "Case #%s: %s" % (case, count)
