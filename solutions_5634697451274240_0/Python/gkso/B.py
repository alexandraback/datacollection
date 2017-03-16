



T = raw_input()
T = int(T)

for i in range(T):
    pancakes = raw_input()
    t = 0
    if pancakes[-1] == '-':
        t += 1
    for j in range(len(pancakes)-1):
        if pancakes[j] != pancakes[j+1]:
            t += 1

    print("Case #%d: %d" % (i + 1, t))




