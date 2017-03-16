for i in range(input()):
    _, y = raw_input().split()

    current_standing = 0
    ans = 0
    for req, num in enumerate(y):
        num = ord(num) - 48
        if num == 0:
            continue
        if current_standing < req:
            ans += req - current_standing
            current_standing += req - current_standing
        current_standing += num

    print "Case #%d:" % (i+1), ans
