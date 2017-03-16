for T in range(int(input())):
    n, k = input().split()
    standing = int(k[0])
    f = 0
    for i in range(1, int(n)+1):
        if standing < i:
            f += i-standing
            standing = i
        standing += int(k[i])
    print ("Case #%d: %d" % (T+1, f))