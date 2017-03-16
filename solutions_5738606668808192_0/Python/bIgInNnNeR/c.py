T = int(input())
N, J = map(int, input().split())


def check(x):
    alc = 0
    idx = 0
    while (1 << idx) <= x:
        if x & (1 << idx):
            alc += 1 - 2 * (idx & 1)
        idx += 1
    return alc == 0

now = 0
alc = 0
for tn in range(1, T + 1):
    print("Case #%d:" % tn)
    while alc < J:
        if check(now):
            alc += 1
            print('1' + '{0:b}'.format(now).zfill(N - 2) + '1', *range(3, 12))
        now += 2
