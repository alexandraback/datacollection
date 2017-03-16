if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        N = int(raw_input())

        l = []
        for i in xrange(N):
            s1, s2 = [int(s) for s in raw_input().split()]
            l += [(s1, 1)]
            l += [(s2, 2)]

        l.sort()
        curr = 0
        spare = 0
        step = 0
        c2 = 0
        curr1 = 0
        impossible = False
        for i in xrange(len(l)):
            if l[i][1] == 2:
                if l[i][0] > curr + curr1:
                    need = l[i][0] - curr - curr1
                    if spare < need:
                        impossible = True
                        break
                    else:
                        spare -= need
                        step += need
                        curr1 += need

                c2 += 1
                curr = c2 * 2
                step += 1

            else:
                if curr + curr1 + spare >= l[i][0]:
                    spare += 1

        if not impossible:
            res = str(step)
        else:
            res = 'Too Bad'

        print 'Case #%d: %s' % (caseno + 1, res)

