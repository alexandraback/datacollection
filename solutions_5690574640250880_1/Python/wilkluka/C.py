def miner(r, c, m):
    # print r, c, m
    if m == 0:
        return 'c' + '.' * (c - 1) + ('\n' + ('.' * c)) * (r - 1)
    elif r > 3:
        if m >= c:
            return miner(r-1, c, m-c) + '\n' + ('*' * c)
        elif m < c - 1:
            return miner(r-1, c, 0) + '\n' + ('.' * (c - m)) + ('*' * m)
        else:
            return miner(r-1, c, 1) + '\n' + ('.' * (c - m + 1)) + ('*' * (m - 1))
    elif r == 3:
        if m >= c and (m-c) % 2 != 1:
            return miner(r-1, c, m-c) + '\n' + ('*' * c)
        else:
            mines = m % 3
            q = (m - mines) / 3 + mines
            return miner(r-1, c, m - q) + '\n' + ('.' * (c - q)) + ('*' * q)
    elif r == 2:
        if m == 1:
            return miner(r-1, c, 0) + '\n' + ('.' * (c - 1)) + '*'
        else:
            return miner(r-1, c, m/2) + '\n' + ('.' * (c - m/2)) + '*' * (m/2)
    else:
        return 'c' + ('.' * (c - m - 1)) + ('*' * m)
    
f = open("C-large.in", 'r')
f_out = open("out_C", 'w')

cases = f.readline()

for case in range(int(cases)):
    mine = f.readline().split()
    R = int(mine[0])
    C = int(mine[1])
    M = int(mine[2])
    free_fields = R * C - M
    if free_fields == 1:
        res = (('*' * C) + '\n' ) * R
        res = 'c' + res[1:-1]
    elif free_fields in [2, 3, 5, 7]:
        if R == 1 or C == 1:
            #print case
            res = miner(R, C, M)
        else:
            res = "Impossible"
    elif free_fields % 2 == 1:
        if R > 2 and C > 2:
            res = miner(R, C, M)
        else:
            res = "Impossible"
    else:
        res = miner(R, C, M)


    print "Case #" + str(case + 1) + ":\n" + res
    f_out.write("Case #" + str(case + 1) + ":\n" + res + '\n')
