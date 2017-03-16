__author__ = 'j0hnny'


if __name__ == '__main__':
    scores = []

    with open('D-large.in', 'r') as input:
        cases = int(input.readline())
        for c in range(cases):
            num_blocks = int(input.readline())

            def blocks():
                return sorted([float(m) for m in input.readline().split()])

            bn = blocks()
            bk = blocks()

            def select(bl, m):
                for b in bl:
                    if b > m:
                        return b

            def calc_score_d():
                n = [x for x in bn]
                k = [x for x in bk]
                s = 0
                for i in range(num_blocks):
                    #print i, s
                    #print n
                    #print k
                    if k[0] > n[0]:
                        m = select(k, n[0])
                        if m is None:
                            s += 1
                            k.remove(k[0])
                        else:
                            k.remove(k[-1])
                    else:
                        s += 1
                        k.remove(k[0])
                    n.remove(n[0])
                return s

            def calc_score_w():
                n = [x for x in bn]
                k = [x for x in bk]
                s = 0
                for i in range(num_blocks):
                    #print i, num_blocks
                    #print n
                    #print k
                    m = select(k, n[0])
                    if m is None:
                        s += 1
                        k.remove(k[0])
                    else:
                        k.remove(m)
                    n.remove(n[0])
                return s

            scores.append((calc_score_d(), calc_score_w()))

    with open('output', 'w') as output:
        for c in range(cases):
            str = 'Case #%d: %d %d\n' % (c+1, scores[c][0], scores[c][1])
            print str
            output.write(str)