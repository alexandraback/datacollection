T = int(raw_input())
for t in xrange(T):
    S = raw_input()
    cs = list(S)
    xs = []
    for c in cs:
        if ([c] + xs) < (xs + [c]):
            xs.append(c)
        else:
            xs.insert(0, c)
    print 'Case #{}: {}'.format(t + 1, ''.join(xs))
