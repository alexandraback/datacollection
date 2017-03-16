from collections import deque

t = int(input())
for tt in range(t):
    c, d, v = map(int, input().split())
    D = list(map(int, input().split()))

    reachable = set()
    for i in range(1 << len(D)):
        b = '{0:0>{1}b}'.format(i, len(D))
        reachable.add(sum(D[j] for j in range(len(D)) if b[j] == '1'))

    required = set(range(v+1))

    r = 0
    missing = required - reachable;
    while len(missing) > 0:
        g = min(missing)
        r += 1
        new = set()
        for i in reachable:
            new.add(i + g)

        reachable |= new
        missing -= new
    print("Case #{}: {}".format(tt+1, r))
