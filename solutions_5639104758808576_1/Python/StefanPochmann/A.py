T = int(input())
for x in range(1, T + 1):
    S = map(int, input().split()[1])
    originals = friends = 0
    for Si, members in enumerate(S):
        if members:
            friends = max(friends, Si - originals)
            originals += members
    print('Case #%d: %d' % (x, friends))
