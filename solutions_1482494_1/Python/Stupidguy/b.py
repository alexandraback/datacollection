t = input()
for testcase in range(1, t+1):
    n, r1, r2, points = input(), [], [], 0
    action = 0
    for x in range(n):
        l1, l2 = map(int, raw_input().split())
        r1.append(l1)
        r2.append(l2)
    updated = True
    while updated and points < n * 2:
        updated = False
        for i in range(n):
            if r2[i] <= points:
                action += 1
                r2[i] = 5000
                points += 2
                if r1[i] == 5000:
                    points -=1
                else:
                    r1[i] = 5000
                updated = True
        if not updated:
            minp = -1
            for i in range(n):
                if r1[i] <= points and (minp == -1 or r2[i] > r2[minp]):
                    minp = i
            if minp != -1:
                action += 1
                r1[minp] = 5000
                points += 1
                updated = True
    if updated and points == n * 2:
        print "Case #" + str(testcase) + ": " + str(action)
    else:
        print "Case #" + str(testcase) + ": Too Bad"

