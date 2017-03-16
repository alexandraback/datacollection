import itertools

t = input()
c = 1

while t:
    case = [int(i) for i in raw_input().split()]
    n = case.pop(0)

    sums = {}
    combos = []

    found = False
    for i in xrange(1, n+1):
        tmp = list(itertools.combinations(case, i))
        tmpsums = [sum(x) for x in tmp]
        for index, s in enumerate(tmpsums):
            if s in sums:
                print 'Case #%d:' % (c,)
                for k in sums[s]:
                    print k,
                print
                for k in tmp[index]:
                    print k,
                print
                found = True
                break
            else:
                sums[s] = tmp[index]
        if found:
            break

    t -= 1
    c += 1
