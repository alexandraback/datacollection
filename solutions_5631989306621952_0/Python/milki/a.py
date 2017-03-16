def main():
    T = int(raw_input())
    for i in xrange(T):
        S = raw_input()
        ret = []
        for c in S:
            if not ret or c >= ret[0]:
                ret = [c] + ret
            else:
                ret.append(c)
        output(i, ''.join(ret))

def output(casenum, ret):
    print 'Case #%d: %s' % (casenum + 1, ret)


main()
