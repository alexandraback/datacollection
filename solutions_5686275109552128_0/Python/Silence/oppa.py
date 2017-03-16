__author__ = 'anton'

def A():
    file = open("input", "r")
    output = open("output", "w")
    lines = [tmp.strip().split(" ") for tmp in file.readlines()[1:]]
    cnt = 1
    for line in lines:
        s = line[1]
        res = 0
        cur = 0
        for i in range(len(s)):
            if (int(s[i]) > 0):
                res = max(res, i - cur)
            cur += int(s[i])
        output.write("Case #" + str(cnt) + ": " + str(res) + "\n")
        cnt += 1
    file.close()
    output.close()

def B():
    cnt = 1
    file = open("input", "r")
    output = open("output", "w")
    lines = [tmp.strip().split(" ") for tmp in file.readlines()[2::2]]
    max = 1001
    for line in lines:
        num = [int(s) for s in line]
        print str(num)
        m = 1000
        for n in range(1, max):
            res = n
            for x in num:
                res += (x - 1) / n
            m = min(m, res)
        output.write("Case #" + str(cnt) + ": " + str(m) + "\n")
        cnt += 1
    file.close()
    output.close()

B()