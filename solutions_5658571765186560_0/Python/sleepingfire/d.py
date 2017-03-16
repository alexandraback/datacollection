import sys

def check(X, R, C):
    # area match
    if (R * C) % X > 0:
        return False

    # min size match
    for i in range(1, int(round(float(X) / 2)) + 1):
        a, b = i, 1 + X - i
        if min(R, C) < min(a, b) or max(R, C) < max(a, b):
            return False

    if X <= 3:
        return True
    if X == 4 and min(R, C) >= 3:
        return True
    return False

#------------------------------------------------
# main process
if __name__ == "__main__":
    path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(path, 'r')

    N = int(in_file.readline())
    for case_num in range(N):
        X, R, C = [int(z) for z in in_file.readline().strip().split()]
        possible = check(X, R, C)
        winner = 'GABRIEL' if possible else 'RICHARD'
        print "Case #{}: {}".format(case_num+1, winner)

    in_file.close()
