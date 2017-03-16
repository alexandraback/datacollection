def least(R, C, W):
    if C % W == 0:
        x = C / W
        return x + (W-1) + (R-1)*x
    else:
        x = C / W
        return x + (W-1) + 1 + (R-1)*x


for i in range(input()):
    R, C, W = map(int, raw_input().split())
    print 'Case #' + str(i+1) + ': ' + str(least(R, C, W))
