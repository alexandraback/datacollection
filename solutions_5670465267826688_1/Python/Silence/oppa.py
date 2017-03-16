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


oppa = dict()
oppa["1"] = 0
oppa["i"] = 1
oppa["j"] = 2
oppa["k"] = 3

class Line:
    def __init__(self, s, rep):
        self.str = [oppa[str(c)] for c in s]
        self.rep = rep

    def __getitem__(self, item):
        return (0, self.str[item % len(self.str)])

    def __len__(self):
        return len(self.str) * self.rep

def mult(x1, x2):
    res1 = [[(0, 0),(0, 1),(0, 2),(0, 3)], [(0,1),(1,0),(0,3),(1,2)], [(0,2),(1,3),(1,0),(0,1)], [(0,3),(0,2),(1,1),(1,0)]][x1[1]][x2[1]]
    return ((res1[0] + x1[0] + x2[0]) % 2, res1[1])


def pow(a, b):
    b = b % 4
    res = (0, 0)
    for i in range(b):
        res = mult(a, res)
    return res


def C():
    cnt = 1
    output = open("output", "w")
    repeats = [int(tmp.strip().split(" ")[1]) for tmp in open("input", "r").readlines()[1::2]]
    lines = [tmp.strip() for tmp in open("input", "r").readlines()[2::2]]
    for rep, line in zip(repeats, lines):
        limit = len(line) * 20
        l = Line(line, rep)
        pos = 0
        fail = False
        for x in [1,2]:
            cur = (0, 0)
            while pos < limit and pos < len(l) and cur != (0, x):
                cur = mult(cur, l[pos])
                pos += 1
            if cur != (0, x):
                fail = True
                break
        prod = (0, 0)
        for i in range(len(line)):
            prod = mult(prod, l[i])
        fail = fail or pow(prod, rep) != (1,0)
        if fail:
            output.write("Case #" + str(cnt) + ": " + "NO" + "\n")
        else:
            output.write("Case #" + str(cnt) + ": " + "YES" + "\n")
        cnt += 1
    output.close()


C()