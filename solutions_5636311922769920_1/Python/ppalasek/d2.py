t = int(raw_input())

for tt in xrange(t):
    k, c, s = map(int, raw_input().split())

    print 'Case #%d:' % (tt + 1), 

    if (s < k and 2 * s < k):
        print 'IMPOSSIBLE'
    else:
        if (c == 1):
            if (s < k):
                print 'IMPOSSIBLE', 
            else:       
                for i in xrange(s):
                    r = i
                    print r + 1,
        else:
            full = [0] * k

            sg = 0
            sp = 0

            res = ''

            for i in xrange(s):
                sg = i * 2
                sp = i * 2 + 1

                if (sp == k):
                    sp -= 1

                full[sg] = 1
                full[sp] = 1

                r = 0
                p = c - 1

                r = sg * k ** p
                r += sp

                print r + 1,

                if (sum(full) == k):
                    break

        print