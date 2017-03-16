def least(C, W):
    if C % W == 0:
        x = C / W
        return x + (W-1)
    else:
        x = C / W
        return x + (W-1) + 1


for i in range(input()):
    R, C, W = map(int, raw_input().split())
    print 'Case #' + str(i+1) + ': ' + str(least(C, W))
