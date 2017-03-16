def explode(s, c):
    t = []
    s += c;
    p = 0;
    for i in range(len(s)):
        if (s[i] == c or s[i] == "\n") and s[p:i] != "" and s[p:i] != "\n":
            t.append(s[p:i])
            p = i + 1
    return t

def eliminated(data, n, s, p):
    votes = p
    score = data[n] + s*p
    for i in range(len(data)):
        if i != n and data[i] < score:
            votes += (score - data[i])/s
    return votes < 1

def solveCase(line):
    data = explode(line, ' ')
    n = int(data[0])
    data = data[1:]
    for i in range(n): data[i] = int(data[i])
    s = sum(data)

    out = ""
    for i in range(n):
        low = 0.0
        high = 1.0
        ans = (low+high)/2
        while abs(low-high) > 0.00000001:
            if eliminated(data, i, s, ans): low = ans
            else: high = ans
            ans = (low+high)/2
        if len(out) > 0: out += " "
        ans = str(round(ans*100, 6))
        if ans.find('e') != -1: ans = "0.000000"
        out += ans
    return out;

def process(data):
    out = ""
    for i in range(1, len(data)):
        if i > 1: out += '\n'
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
