infile = "input.txt"
outfile = "python.txt"
FIN = open(infile)
FOUT = open(outfile, "w")
tests = int(FIN.readline())
for i in range(tests):
    r, t = map(int, FIN.readline().split())
    left = 1
    right = 1000000000
    while (right - left > 1):
        mid = (left + right) // 2
        if (2 * mid * r + (2 * mid - 1) * mid <= t):
            left = mid
        else:
            right = mid
    FOUT.write("Case #" + str(i + 1) + ": " + str(left) + "\n")