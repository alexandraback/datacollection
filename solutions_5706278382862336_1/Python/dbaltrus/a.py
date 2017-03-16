import sys

lines = sys.stdin.readlines()
T = int(lines[0])
for t in range(1, T + 1):
    nom, denom = map(int, lines[t].strip().split('/'))
    if 2**40 * nom % denom == 0:
        for i in range(1, 41):
            if 2**i * nom // denom > 0:
                print('Case #{}: {}'.format(t, i))
                break
    else:
        print('Case #{}: impossible'.format(t))

