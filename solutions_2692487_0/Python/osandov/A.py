def solve(armin, others):
    if armin == 1:
        return len(others)
    else:
        for i, v in enumerate(others):
            if armin > v:
                armin += v
            else:
                extras_armin, extras_r = extras(armin, v)
                extras_r += solve(extras_armin, others[i:])
                remove_r = 1 + solve(armin, others[i + 1:])
                return min(extras_r, remove_r)
        return 0

def extras(armin, other):
    r = 0
    while armin <= other:
        armin += armin - 1
        r += 1
    return armin, r

if __name__ == '__main__':
    for i in range(input()):
        [armin, n] = [int(x) for x in raw_input().split()]
        others = [int(x) for x in raw_input().split()]
        print 'Case #{}: {}'.format(i + 1, solve(armin, sorted(others)))
