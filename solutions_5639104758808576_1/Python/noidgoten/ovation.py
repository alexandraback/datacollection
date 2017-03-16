file = open("ovation.in", "r")

filew = open("ovation.out", "w")

def run(smax, hm, sum, t):
    if sum == 0:
        filew.write("Case #" + str(t) + ": 0\n")
    else:
        up = hm[0]
        res = 0
        for i in range(1, smax + 1):
            if up >= i:
                up += hm[i]
            else:
                if hm[i] != 0:
                    add = i - up
                    up += add + hm[i]
                    res += add
        filew.write("Case #" + str(t) + ": " + str(res) + "\n")

t = int(file.readline())

for i in range(t):
    x = file.readline().split()
    smax = int(x[0])
    hm = []
    sum = 0
    for j in range(smax + 1):
        y = int(x[1][j])
        sum += y
        hm.append(y)
    run(smax, hm, sum, i + 1)