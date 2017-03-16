t = int(raw_input())

for it in range(1, t + 1):
    (K, C, S) = map(int, raw_input().split(' '))
    out = ' '.join(map(str, range(1, K + 1)))
    print "Case #{}: {}".format(it, out)
