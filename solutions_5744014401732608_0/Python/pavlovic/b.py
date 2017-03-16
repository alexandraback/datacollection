import sys

t = int(sys.stdin.readline().strip())
for i in range(t):
    sys.stdout.write("Case #%d: " % (i + 1))    
    b, m = map(int, sys.stdin.readline().strip().split())

    if (m > pow(2, b - 2)):
        sys.stdout.write("IMPOSSIBLE\n")
        continue

    sys.stdout.write("POSSIBLE\n")

    s = "0"
    for j in range(b - 1):
        if m >= pow(2, b - j - 3):
            s += "1"
            m -= pow(2, b - j - 3)
        else:
            s += "0"
            
    sys.stdout.write("%s\n" % s)

    for j in range(b - 1):
        s = "0" * (j + 2) + "1" * (b - j - 2)
        sys.stdout.write("%s\n" % s)

