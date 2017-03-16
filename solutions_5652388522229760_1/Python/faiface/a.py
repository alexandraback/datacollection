t = int(input())

for q in range(t):
    n = int(input())
    if n == 0:
        print('Case #{}: INSOMNIA'.format(q + 1))
        continue

    m = 0
    seen = set()

    while len(seen) < 10:
        m += n
        seen |= set(str(m))

    print('Case #{}: {}'.format(q + 1, m))
