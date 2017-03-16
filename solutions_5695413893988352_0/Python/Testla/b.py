t = int(input())

def match(x, y):
    for a, b in zip(x, y):
        if a != b and b != '?':
            return False
    return True

for ti in range(1, t + 1):
    a, b = input().split()
    m = 100000000000
    ba = None
    bb = None
    for i in range(10 ** len(a)):
        if match('%%0%dd' % len(a) % i, a):
            for j in range(10 ** len(a)):
                if match('%%0%dd' % len(a) % j, b):
                    if m > abs(i - j):
                        m = abs(i - j)
                        ba = '%%0%dd' % len(a) % i
                        bb = '%%0%dd' % len(a) % j
    print('Case #' + str(ti) + ': ' + ba + ' ' + bb)