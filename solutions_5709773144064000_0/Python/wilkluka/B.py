f = open("b0.in", 'r')
f_out = open("out_B", 'w')

cases = f.readline()

for case in range(int(cases)):
    clicker = f.readline().split()
    C = float(clicker[0])
    F = float(clicker[1])
    X = float(clicker[2])
    n = (X - C) / C - 2/F
    n = max(int(n+1), 0)
    time = 0
    # print n
    for i in range(n):
        time += C/(2.0 + i * F)
        # print "!!!!!", time , "#########3", time + X/(2.0 + (i+1)*F)
    time += X/(2.0 + n*F)
    f_out.write("Case #" + str(case + 1) + ": " + str(time) + "\n")
