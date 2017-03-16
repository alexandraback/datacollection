def solve():
    line = input().strip()
    l = []
    for c in line:
        if not l or c >= l[0]:
            l.insert(0, c)
        else:
            l.append(c)
    return ''.join(l)

round = int(input())
for r in range(1,round+1):
    print('Case #{}: {}'.format(r, solve()))
