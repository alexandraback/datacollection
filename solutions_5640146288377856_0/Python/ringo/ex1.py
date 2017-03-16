f = open('A-small-attempt0.in', 'r')
g = open('output.txt', 'w')


num = int(f.readline())
for i in range (num):
    data = f.readline().split()
    R = int(data[0])
    C = int(data[1])
    W = int(data[2])

    poss = C - W + 1
    count = 0
    while poss > 0:
        count += 1
        poss -= W

    poss += W

    ans = (count*R + (W-1))

    if poss > 1:
        ans += 1

    s = "Case #" + str(i+1) + ": " + str(ans) + '\n'
    g.write(s)

f.close()
g.close()


