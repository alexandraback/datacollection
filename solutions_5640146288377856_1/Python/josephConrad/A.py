T = int(raw_input())

for i in range(T):
    R, C, W = map(int, raw_input().split(" "))
    rows = (C/W) * (R-1)
    if C % W == 0:
        print "Case #" + str(i+1) + ": " + str(rows + (C / W) + W - 1)
    else:
        print "Case #" + str(i+1) + ": " + str(rows + (C / W) + W)
