def explode(s, c):
    t = []
    s += c;
    p = 0;
    for i in range(len(s)):
        if (s[i] == c or s[i] == "\n") and s[p:i] != "" and s[p:i] != "\n":
            t.append(s[p:i])
            p = i + 1
    return t

def solveCase(line):
    data = explode(line, " ")
    c = float(data[0])
    f = float(data[1])
    x = float(data[2])
    n = 0
    t = 0
    if (x < c): return x / 2
    while (True):
        dt = c / (2 + n*f)
        t += dt
        buyanother = x / (2 + (n+1)*f)
        nomore = (x - c) / (2 + n*f)
        if (nomore < buyanother): return t + nomore
        n += 1
    return t;

def process(data):
    out = ""
    for i in range(1, len(data)):
        if i > 1: out += '\n'
        out += "Case #" + str(i) + ": "
        out += str(solveCase(data[i]))
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

main("large")
