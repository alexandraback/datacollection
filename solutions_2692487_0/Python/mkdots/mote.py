import sys

def absorb(armin, motes):
    if (armin == 1):
        return len(motes)

    blob = armin
    for mote in motes:
        if mote >= blob:
            break
        blob = blob + mote

    remaining = filter(lambda x: x >= blob, motes)
    best = len(remaining)
    additional = 0
    n = len(remaining)
    for i in range(n):
        if (blob > remaining[i]):
            blob = blob + remaining[i]
            continue

        if best > additional + (n - i):
            best = additional + (n - i)

        k = 1
        while 2**k * (blob - 1) + 1 <= remaining[i]:
            k = k + 1
        additional = additional + k
        blob = 2**k * (blob - 1) + 1
        blob = blob + remaining[i]

    if additional < best:
        best = additional
    return best

s = sys.stdin
T = int(s.readline())
for t in range(T):
    armin, n = map(int, s.readline().split())
    sys.stdout.write("Case #{}: {}\n".format(t + 1,
        absorb(armin, sorted(map(int, s.readline().split())))))
