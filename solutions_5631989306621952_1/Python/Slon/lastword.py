import sys

T=int(sys.stdin.readline().strip())

for t in range(1, T + 1):
    L = sys.stdin.readline().strip()
    last = ""
    for c in L:
        if last + c > c + last:
            last = last + c
        else:
            last = c + last
    print("Case #%d: %s" % (t, last))
