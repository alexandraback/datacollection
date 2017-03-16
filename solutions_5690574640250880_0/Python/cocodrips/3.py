def solve(n, R, C, M):
    if R >= 2 and C >= 2:
        if 1 < R * C - M < 4:
            outfile.write("Impossible\n")
            return


    # Long Case
    data = []
    if R == 1:
        data = [['.'] * C]
        data[0][0] = "c"
        for i in xrange(C - M, C):
            data[0][i] = "*"

    elif C == 1:
        data = [["."] for i in xrange(R)]
        data[0][0] = "c"
        for i in xrange(R - M, R):
            data[i][0] = "*"

    else:
        data = [["*"] * C for i in xrange(R)]
        # 2 x 2  and M == 1
        data[0][0] = "c"
        if R * C - M != 1:
            data[0][1] = data[1][0] = data[1][1] = "."

            if M - (R-2)*(C-2) > 0 and (M - (R-2)*(C-2)) % 2 == 1:
                if R * C - M < 9 or R < 3 or C < 3:
                    outfile.write("Impossible\n")
                    return
                nokori = M
                umeru2(data, R, C, nokori)
                for r in xrange(3):
                    for c in xrange(3):
                        data[r][c] = "."
                data[1][1] = 'c'

            else:
                nokori = M
                umeru(data,R,C,nokori)

    cnt = 0
    for d in data:
        for dd in d:
            if dd == '*':
                cnt+=1
    if cnt != M:
        print n


    for d in data:
        outfile.write("{0}\n".format("".join(d)))
    # print data
    return


def umeru(data, R, C, nokori):
    for r in xrange(R):
        start = 0
        if r == 0 or r == 1:
            start = 2
        for c in xrange(start, C):
            data[r][c] = "."


    for r in range(2, R)[::-1]:
        for c in range(2, C)[::-1]:
            if nokori == 0:
                return
            data[r][c] = "*"
            nokori -= 1

    for r in range(2, R)[::-1]:
        for c in xrange(2):
            if nokori == 0:
                return
            data[r][c] = "*"
            nokori -= 1

    for c in range(2, C)[::-1]:
        for r in range(2):
            if nokori == 0:
                return
            data[r][c] = "*"
            nokori -= 1

def umeru2(data, R, C, nokori):
    for r in xrange(R):
        for c in xrange(C):
            if r < 3 and c < 3:
                data[r][c] = "-"
            else:
                data[r][c] = "."

    for r in range(2, R)[::-1]:
        for c in range(2, C)[::-1]:
            if data[r][c] == '-':
                continue
            if nokori == 0:
                return
            data[r][c] = "*"
            nokori -= 1

    for r in range(3, R)[::-1]:
        for c in xrange(2):
            if nokori == 0:
                return
            data[r][c] = "*"
            nokori -= 1

    for c in range(3, C)[::-1]:
        for r in range(2):
            if nokori == 0:
                return
            data[r][c] = "*"
            nokori -= 1












if __name__ == "__main__":
    with open('3input-small-honban', 'r') as infile, open('3output-small-honban.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(map(int, line.split()))

        N = data.pop(0)[0]
        for n in xrange(N):
            # if n+1 != 26:
            #     continue
            R, C, M = data.pop(0)
            outfile.write("Case #{0}:\n".format(n+1))
            solve(n+1, R, C, M)


