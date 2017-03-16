def solve_case(case, B, M):
    edges = [['0' for i in xrange(B)] for j in xrange(B)]
    if M > 2 ** (B - 2):
        print 'Case #%d: IMPOSSIBLE' % case
        return
    else:
        print 'Case #%d: POSSIBLE' % case
    for i in xrange(1, B):
        for j in xrange(i + 1, B):
            edges[i][j] = '1'
    if M == 2 ** (B - 2):
        carry = True
        M -= 1
    else:
        carry = False
    binary = "{0:b}".format(M)

    first_line = [i for i in binary]
    if carry:
        first_line.append('1')
    else:
        first_line.append('0')
    while len(first_line) < B:
        first_line.insert(0, '0')
    edges[0] = first_line

    for line in edges:
        print ''.join(line)

if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as fd:
        lines = [line.strip() for line in fd.readlines()]
    for case in xrange(1, len(lines)):
        B, M = [int(i) for i in lines[case].split()]
        solve_case(case, B, M)
