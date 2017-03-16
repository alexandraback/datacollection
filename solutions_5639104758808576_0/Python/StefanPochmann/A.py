with open('A-small-attempt0.in') as f, open('A.out', 'w') as g:
    next(f)
    for x, line in enumerate(f, 1):
        S = map(int, line.split()[1])
        originals = friends = 0
        for Si, members in enumerate(S):
            if members:
                friends = max(friends, Si - originals)
                originals += members
        print('Case #%d: %d' % (x, friends), file=g)
