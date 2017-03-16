import sys
T = int(sys.stdin.readline())
for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    i = int(sys.stdin.readline())
    if i == 0:
        sys.stdout.write("INSOMNIA\n")
        continue
    seen = set()
    steps = 0
    while seen != set("1234567890"):
        steps += 1
        seen |= set(str(i*steps))
    sys.stdout.write("%d\n" % (i*steps))
