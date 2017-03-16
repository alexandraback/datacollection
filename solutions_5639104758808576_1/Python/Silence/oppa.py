__author__ = 'anton'

def __main__():
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

__main__()