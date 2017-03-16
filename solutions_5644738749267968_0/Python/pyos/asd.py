from sys import stdin


_readstr  = lambda: stdin.readline().strip()
_readlist = lambda: stdin.readline().split()
_readint  = lambda: int(_readstr())



def deceitful(xs, ys):
    c  = 0
    xs = set(xs)
    ys = set(ys)

    for _ in range(len(xs)):
        try:
            dn = min(ys)
            # By saying that the block is heavier than anything Ken has to offer,
            # Naomi ensures that he will give up the lightest one.
            # For this to work optimally, though, the block should actually
            # be heavier than the one Ken is expected to yield (he'll notice
            # the fraud otherwise), but as light as possible.
            xs.remove(min({x for x in xs if dn < x}))
            ys.remove(min(ys)) 
            c += 1

        except ValueError:
            try:
                up = max(ys)
                # Failing that, Naomi may choose to offer her lightest block
                # and say it's only slightly lighter than Ken's heaviest one.
                # This will give her no points, but will make the normal War easier.
                xs.remove(min({x for x in xs if x < up}))
                ys.remove(up)
            except ValueError:
                # And the best strategy: play normally and pray for the best.
                # Note that there's no way to satisfy the above conditions
                # after failing them once.
                return c + normal(xs, ys)

    return c


def normal(xs, ys):
    c  = 0
    xs = set(xs)
    ys = set(ys)

    for _ in range(len(xs)):
        x  = max(xs)
        y  = min({y for y in ys if y > x} or {min(ys)})
        c += x > y
        xs.remove(x)
        ys.remove(y)

    return c


for n in range(_readint()):
    _readint()
    xs = set(map(float, _readlist()))
    ys = set(map(float, _readlist()))

    print('Case #{}: {} {}'.format(n + 1, deceitful(xs, ys), normal(xs, ys)))

