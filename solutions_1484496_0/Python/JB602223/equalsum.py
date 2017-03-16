def explode(s, c):
    t = []
    s += c;
    p = 0;
    for i in range(len(s)):
        if (s[i] == c or s[i] == "\n") and s[p:i] != "" and s[p:i] != "\n":
            t.append(s[p:i])
            p = i + 1
    return t

memo = {}

def solve(s1, s2, setR, set1, set2):
    global memo
    if s1 == s2 and s1 > 0: return [set1, set2]
    key = str(s1) + ' ' + str(s2) + str(set2)
    if key in memo: return -1
    for i in setR:
        if s1 + i == s2 and s2 > 0: return [set1+[i,], set2]
        if s2 + i == s1 and s1 > 0: return [set1, set2+[i,]]
        temp = []
        for j in setR: temp.append(j)
        temp.remove(i)
        ans = solve(s1, s2, temp, set1, set2)
        if ans != -1: return ans
        ans = solve(s1, s2 + i, temp, set1, set2+[i,])
        if ans != -1: return ans
        ans = solve(s1 + i, s2, temp, set1+[i,], set2)
        if ans != -1: return ans
    memo[key] = True
    return -1

def solveCase(line):
    global memo
    print len(memo)
    memo.clear()
    print len(memo)
    data = explode(line, ' ')
    n = int(data[0])
    data = data[1:]
    for i in range(n): data[i] = int(data[i])

    ans = solve(0, 0, data, [], [])
    if ans == -1: return "Impossible"
    out = "\n"
    for i in ans[0]: out += str(i) + " "
    out += "\n"
    for i in ans[1]: out += str(i) + " "
    print out
    return out

def process(data):
    out = ""
    for i in range(1, len(data)):
        if i > 1: out += '\n'
        print "Solving Case #" + str(i) + " " + str(len(memo))
        out += "Case #" + str(i) + ": "
        out += solveCase(data[i])
    return out

def main(fn):
    iFile = open(fn + ".in", "r")
    oFile = open(fn + ".out", "w")
    print("Files opened.")

    data = []
    while True:
        line = iFile.readline()
        if not line: break
        data.append(line)

    out = process(data)
    print("Calculations complete. Outputting to file.")
    oFile.writelines(out)
    print("Output complete.")
    iFile.close()
    oFile.close()
    print("Files closed.")

main("small")
