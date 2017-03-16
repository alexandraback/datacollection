# D. Ominous Omino

def possible(x, r, c):
    if x >= 7:
        return False
    if (r * c) % x != 0:
        return False
    if r < x and c < x:
        return False
    if x > 2 and (r <= x / 2 or c <= x / 2):
        return False
    return True

t = input()
for case in range(t):
    (x, r, c) = [int(s) for s in raw_input().rstrip().split(' ')]
    print "Case #" + str(case + 1) + ":",
    print 'GABRIEL' if possible(x, r, c) else 'RICHARD'
