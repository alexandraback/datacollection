filename = "B-small-attempt0.in" # change later
f = open(filename)
T = int(f.readline())
for case in range(1,T+1):
    s = f.readline()
    s = s.split()
    X = int(s[0])
    Y = int(s[1])
    step = 0
    x = 0
    y = 0
    ans = ""
    while x != X or y != Y:
        step = step + 1
        if abs(x + step - X) < abs(x - X):
            ans = ans + 'E'
            x = x + step
            continue
        elif abs(x - step - X) < abs(x - X):
            ans = ans + 'W'
            x = x - step
            continue
        elif abs(y + step - Y) < abs(y - Y):
            ans = ans + 'N'
            y = y + step
            continue
        elif abs(y - step - Y) < abs(y - Y):
            ans = ans + 'S'
            y = y - step
            continue
            
        elif x != X:
            if x < X:
                ans = ans + 'W'
                x = x - step
                continue
            else:
                ans = ans + 'E'
                x = x + step
                continue
        elif y != Y:
            if y < Y:
                ans = ans + 'S'
                y = y - step
                continue
            else:
                ans = ans + 'N'
                y = y + step
                continue
    #whileend
    print "Case #" + str(case) + ": " + ans
    