N = int(raw_input())
for I in xrange(N):
    pks = raw_input()
    compressed = ''
    last = None
    for c in pks:
        if c != last:
            compressed += c
            last = c
    happy = [c == '+' for c in compressed[::-1]]
    toFlip = False
    flips = 0
    for p in happy:
        if p == toFlip:
            flips += 1
            toFlip = not toFlip
    print('Case #{}: {}'.format(I + 1, flips))
