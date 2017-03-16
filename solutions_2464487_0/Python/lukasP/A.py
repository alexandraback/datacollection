from sys import stdin

def riadok():
    return map(int, stdin.readline().split())

for cas in range(int(stdin.readline())):
    r, t = riadok()
    z, k = 0, 10 ** 20
    while z + 1 < k:
        n = (z + k) / 2
        need = 2 * n * (r + n) - n

        if need <= t:
            z = n
        else:
            k = n
    print "Case #%d: %d" % (cas + 1, z)
