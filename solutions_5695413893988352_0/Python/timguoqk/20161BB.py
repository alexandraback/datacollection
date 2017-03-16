# https://code.google.com/codejam/contest/11254486/dashboard#s=p1
filein = open('20161BB.in', 'r')
fileout = open('20161BB.out', 'w')

T = int(filein.readline())


def solve(c, j):
    c, j = list(c), list(j)
    # Assume c > j
    first_pos = -1
    for i in range(len(c)):
        if c[i] != '?' and j[i] != '?' and c[i] != j[i]:
            first_pos = i
            break
    if first_pos == -1:
        # No such pos exists, assign 0 if possible
        for i in range(len(c)):
            if c[i] == '?':
                if j[i] == '?':
                    c[i], j[i] = '0', '0'
                else:
                    c[i] = j[i]
            else:
                assert(j[i] == '?' or c[i] == j[i])
                j[i] = c[i]
    else:
        if c[first_pos] > j[first_pos]:
            # Max c min j
            for i in range(first_pos):
                if c[i] == '?' and j[i] != '?':
                    c[i] = j[i]
                elif c[i] != '?' and j[i] == '?':
                    j[i] = c[i]
                c[i] = '0' if c[i] == '?' else c[i]
                j[i] = '0' if j[i] == '?' else j[i]
        else:
            # Find the closest ?
            first_unknown_pos = -1
            for i in reversed(range(first_pos)):
                if c[i] == '?' or j[i] == '?':
                    # Some edge cases
                    # if j[i] == '9': or c[i] == '0':
                    #     continue
                    if j[i] == '9':
                        c[i] = '0'
                        continue
                    if c[i] == '0':
                        j[i] == '9'
                        continue
                    first_unknown_pos = i
                    break

            if first_unknown_pos == -1:
                return (None, None)

            if c[first_unknown_pos] == '?':
                if j[first_unknown_pos] == '?':
                    c[first_unknown_pos] = '1'
                    j[first_unknown_pos] = '0'
                # elif j[first_unknown_pos] == '9':
                #     pass
                else:
                    c[first_unknown_pos] = str(int(j[first_unknown_pos]) + 1)
            else:
                # if c[first_unknown_pos] == '0':
                #     pass
                j[first_unknown_pos] = str(int(c[first_unknown_pos]) - 1)

            for i in range(first_unknown_pos):
                if c[i] == '?' and j[i] != '?':
                    c[i] = j[i]
                elif c[i] != '?' and j[i] == '?':
                    j[i] = c[i]
                c[i] = '0' if c[i] == '?' else c[i]
                j[i] = '0' if j[i] == '?' else j[i]

            for i in range(first_unknown_pos, first_pos):
                if c[i] == '?' and j[i] != '?':
                    c[i] = j[i]
                elif c[i] != '?' and j[i] == '?':
                    j[i] = c[i]
                c[i] = '0' if c[i] == '?' else c[i]
                j[i] = '9' if j[i] == '?' else j[i]

        for i in range(first_pos, len(c)):
            c[i] = '0' if c[i] == '?' else c[i]
            j[i] = '9' if j[i] == '?' else j[i]
    # print(c)
    return (''.join(c), ''.join(j))


for t in range(T):
    fileout.write('Case #%d: ' % (t + 1))
    c, j = filein.readline().strip().split()
    print((c, j))
    c1, j1 = solve(c, j)
    print((j, c))
    j2, c2 = solve(j, c)
    if c1 is None and j1 is None:
        assert(c2 and j2)
        c1, j1 = c2, j2
    elif c2 is None and j2 is None:
        assert(c1 and j1)
    else:
        diff = abs(int(c2) - int(j2)) - abs(int(c1) - int(j1))
        if diff < 0 or \
            (diff == 0 and
                (int(c2) < int(c1) or
                    (int(c2) == int(c1) and int(j2) < int(j1))
                 )
             ):
            c1, j1 = c2, j2
    fileout.write(c1 + ' ' + j1 + '\n')

filein.close()
fileout.close()
