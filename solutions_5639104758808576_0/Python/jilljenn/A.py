T = int(raw_input())
for t in range(T):
    nb_stand = 0
    r = 0
    smax, number = raw_input().split()
    smax = int(smax)
    for required in range(smax + 1):
        if number[required] == '0':
            continue
        if nb_stand + r < required:
            # print('%d: add %d people' % (required, required - nb_stand))
            r += required - (nb_stand + r)
        nb_stand += int(number[required])
    print 'Case #%d: %s' % (t + 1, r)
