def main():
    kBase = 2 ** 40

    with open('A-small-attempt1.in') as f:
        T = int(f.readline())
        for tc in xrange(1, T + 1):
            P, Q = [int(x) for x in f.readline().split('/')]
            P *= kBase
            if (P % Q != 0):
                print "Case #%i: impossible" % tc
            else:
                K = P / Q
                answer = 40
                while K >= 2:
                    answer -= 1
                    K /= 2
                print "Case #%i: %i" % (tc, answer)


if __name__ == '__main__':
    main()
