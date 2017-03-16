def attempt(targetx, targety) :
    attemptq = [("", 0, 0)]

    while len(attemptq) > 0 :
        path = attemptq.pop(0)
        print path[0]
        i = len(path[0]) + 1
        if (path[1] + i, path[2]) == (targetx, targety) :
            return path[0] + 'E'
        else :
            attemptq.append((path[0] + 'E', path[1] + i, path[2]))
        if (path[1] - i, path[2]) == (targetx, targety) :
            return path[0] + 'W'
        else :
            attemptq.append((path[0] + 'W', path[1] - i, path[2]))
        if (path[1], path[2] + i) == (targetx, targety) :
            return path[0] + 'N'
        else :
            attemptq.append((path[0] + 'N', path[1], path[2] + i))
        if (path[1], path[2] - i) == (targetx, targety) :
            return path[0] + 'S'
        else :
            attemptq.append((path[0] + 'S', path[1], path[2] - i))

    return ""

t = int(raw_input())
for casenum in range(1, t + 1) :
    x, y = [int(z) for z in raw_input().split()]
    path = ""

    if x > 0 :
        for i in range(0, x) :
            path += "WE"
    else :
        for i in range(0, -x) :
            path += "EW"
    if y > 0 :
        for i in range(0, y) :
            path += "SN"
    else :
        for i in range(0, -y) :
            path += "NS"

    print "Case #%d: %s" % (casenum, path)
