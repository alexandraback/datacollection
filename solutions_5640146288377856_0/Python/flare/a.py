for t in range(int(input())):
    data = raw_input().split()
    #print data
    ans = 0
    R = int(data[0])
    C = int(data[1])
    W = int(data[2])
    cfind = C / W
    ans = cfind * R
    if  C % W != 0:
        ans += W
    else:
        ans += W - 1
    print('Case #%d: %s' % (t + 1, ans))