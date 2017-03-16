def simulate(farms):
    time = 0
    rate = 2
    while farms:
        time += c / rate
        rate += f
        farms -= 1
    return time + x / rate

for TC in range(1, int(raw_input())+1):
    c, f, x = map(float, raw_input().split())
    fastest = x / 2
    farms = 1
    while True:
        time = simulate(farms)
        if time > fastest:
            farms = farms / 2 + 1
            break
        farms *= 2
        fastest = time
    # fine tune
    while True:
        time = simulate(farms)
        if time > fastest:
            break
        farms += 1
        fastest = time
    print "Case #%d: %.7f" % (TC, fastest)