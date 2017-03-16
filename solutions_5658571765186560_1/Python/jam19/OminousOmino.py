import math

sample = "sample"
small = "D-small-attempt5"
large = "D-large"
current = large

fin = open(current + ".in", "r")
fout = open(current + ".out", 'w')
# f1out = open(current + "1.out", 'w')
# f2out = open(current + "2.out", 'w')

T = int(fin.readline())

Gabriel = "GABRIEL"
Richard = "RICHARD"

def solve(X, R, C):
    if (R * C) % X != 0:
        print "%"
        return Richard
    if R < X and C < X:
        print "<"
        return Richard
    if X > 6:
        print "6"
        return Richard
    min_l = 1 + (X - 1) / 2
    if X > 2 and (R < min_l or C < min_l):
        print "sqrt"
        return Richard
    snake = 2 + (X - 2) / 3
    if X > 3 and (R <= snake or C <= snake):
        print "snake"
        if X == 4:
            return Richard
        elif X == 5 and (R < 5 and C < 5):
            return Richard
        elif X == 6 and (R < 7 and C < 7):
            return Richard

    return Gabriel

for i in range(T):
    X, R, C = map(int, fin.readline().split())
    print i+1, X, R, C

    solution = solve(X, R, C)
    # if solution > candidate:
    #     print 'ERROR', i + 1, solution, candidate
    # if solution != solution1:
    #     print 'ERROR', i + 1, solution, solution1, candidate
    answer = "Case #%d: %s\n" % (i + 1, solution)
    print answer
    fout.write(answer)

fin.close()
fout.close()
# f1out.close()
# f2out.close()
