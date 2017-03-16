from itertools import combinations

def setify(s):
    s = [x for x in zip(*s)]
    return [set(x) for x in s]

def check(old, new):
    # a = map(set, zip([x.split() for x in old]))
    # b = map(set, zip([x.split() for x in new]))
    return a == b

t = int(input().strip())
for tc in range(1, t+1):
    n = int(input().strip())
    lines = [input().split() for _ in range(n)]
    old = setify(lines)
    for i in range(n+1):
        done = False
        for new in combinations(lines, i):
            if old == setify(new):
                print('Case #{}: {}'.format(tc, n-i))
                done = True
                break
        if done:
            break
