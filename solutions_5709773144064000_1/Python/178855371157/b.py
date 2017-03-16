import sys

T = int(sys.stdin.readline())

def is_sorted(a):
    for i in range(0, len(a) - 1):
        if a[i] <= a[i + 1]:
            return False
    return True

def is_zig(a):
    i = 1
    while i < len(a):
        if a[i-1] <= a[i]:
             break
        i += 1
    while i < len(a):
        if a[i-1] > a[i]:
             break
        i += 1
    return i == len(a)

for i in range(1, T+1):
    [C, F, X] = [float(f) for f in sys.stdin.readline()[:-1].split(' ')]

    f_time = 0
    time = X / 2.0
    min_time = time
    for j in range(1, 1000000):
        new_f_time = f_time + C / (2.0 + F * (j - 1))
        new_time = new_f_time + X / (2.0 + F * j)
        if new_time <= min_time:
            min_time = new_time
        else:
            break
        f_time = new_f_time
        time = new_time

    print "Case #{}: {:.10f}".format(i, min_time)
