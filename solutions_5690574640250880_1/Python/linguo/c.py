# Find x[0], x[1], x[2], ..., x[R - 1] 
#  with x[0] <= x[1] <= x[2] <= ... <= x[R - 2]
#  and x[R - 2] = x[R - 1] <= C
# Such that for no i is x[i] == 1

# Such that R * C = M + x[0] + x[1] + ... + x[R - 1]

def solution(R, C, M):
    if R == 1:
        return [["*"] * M + ["."] * (C - (M + 1)) + ["c"]]
    if C == 1:
        return [["*"]] * M + [["."]] * (R - (M + 1)) + [["c"]]
    if M == R * C - 1:
        return [["c" if (i + j == 0) else "*" for j in xrange(C)] for i in xrange(R)]
    if M == R * C - 2:
        return []
    if M == R * C - 3:
        return []
    if M == R * C - 4:
        return [["c" if (i + j == 0) else "." if (max(i,j) == 1) else "*" for j in xrange(C)] for i in xrange(R)]
    if C == 2:
        if (M % 2) == 0:
            return [["*" for i in xrange(2)] for j in xrange(M/2)] + [["." for i in xrange(2)] for j in xrange(R - (M / 2) - 1)] + [[".","c"]]
        else:
            return []
    if R == 2:
        if (M % 2) == 0:
            return [["*" for i in xrange(M/2)] + ["." for i in xrange(C - (M / 2) - 1)] + [j] for j in ".c"]
        else:
            return []
    if M == R * C - 5:
        return []
    if M == R * C - 7:
        return []
    lft = R * C - M
    if lft <= 2 * C + 1:
        if ((lft & 1) == 0):
            return [[j] + ["."] * (lft / 2 - 1) + ["*"] * (C - (lft / 2)) for j in "c."] + [["*"] * C for i in xrange(R - 2)]
        return [[j] + ["."] * ((lft - 3) / 2 - 1) + ["*"] * (C - ((lft - 3) / 2)) for j in "c."] + [["."] * 3 + ["*"] * (C - 3)] + [["*"] * C for i in xrange(R - 3)]
    grid = []
    while lft >= C + 2:
        grid += [["."] * C]
        lft -= C
    if lft == C + 1:
        grid += [["."] * (C - 1) + ["*"]]
        grid += [["."] * 2 + ["*"] * (C - 2)]
    else:
        grid += [["."] * lft + ["*"] * (C - lft)]
    grid += [["*"] * C for i in xrange(len(grid),R)]
    grid[0] = ["c"] + grid[0][1:]
    return grid

from sys import stdin

for R in xrange(1,6):
    for C in xrange(1,6):
        for M in xrange(0, R*C):
            ans = solution(R, C, M)
            shouldBeImpossible = (((R == 2) or (C == 2)) and (R > 1) and (C > 1) and ((((M % 2) == 1) and (M != R * C - 1)) or (M == R * C - 2))) or ((R > 2) and (C > 2) and ((R * C - M) in [2,3,5,7]))
            if (len(ans) == 0) != shouldBeImpossible:
                print "Error 1: (%d, %d, %d)" % (R, C, M)
                print "\n".join(["".join(row) for row in ans])
                exit(0)
            elif (len(ans) > 0):
                if len(ans) != R:
                    print "Error 2: (%d, %d, %d)" % (R, C, M)
                    print "\n".join(["".join(row) for row in ans])
                    exit(0)
                if len([row for row in ans if len(row) != C]) != 0:
                    print "Error 3: (%d, %d, %d)" % (R, C, M)
                    print "\n".join(["".join(row) for row in ans])
                    exit(0)
                if len([sq for row in ans for sq in row if sq == "*"]) != M:
                    print "Error 4: (%d, %d, %d)" % (R, C, M)
                    print "\n".join(["".join(row) for row in ans])
                    exit(0)
                if len([sq for row in ans for sq in row if sq == "c"]) != 1:
                    print "Error 4: (%d, %d, %d)" % (R, C, M)
                    print "\n".join(["".join(row) for row in ans])
                    exit(0)
                ans2 = [[z for z in k] for k in ans]
                for i in xrange(R):
                    for j in xrange(C):
                        if ans[i][j] == ".":
                            if len([i2 for i2 in xrange(max(i-1,0),min(i+1,R-1)+1) for j2 in xrange(max(j-1,0),min(j+1,C-1)+1) if ans[i2][j2] == "*"]) == 0:
                                ans[i] = ans[i][:j] + ["c"] + ans[i][(j+1):]
                for i in xrange(R):
                    for j in xrange(C):
                        if ans[i][j] == ".":
                            if len([i2 for i2 in xrange(max(i-1,0),min(i+1,R-1)+1) for j2 in xrange(max(j-1,0),min(j+1,C-1)+1) if ans[i2][j2] == "c"]) == 0:
                                print "Error 5: (%d, %d, %d)" % (R, C, M)
                                print "\n".join(["".join(row) for row in ans2])

for cn in xrange(1,int(stdin.readline())+1):
    [R, C, M] = [int(z) for z in stdin.readline().split()]
    ans = solution(R, C, M)
    print "Case #%d:" % cn
    if len(ans) == 0:
        print "Impossible"
    else:
        print "\n".join(["".join(row) for row in ans])
