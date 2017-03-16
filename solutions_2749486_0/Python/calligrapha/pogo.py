def solve(line):
    X, Y = (int(x) for x in line.split())
    line = 0
    col = 0
    step = 1
    result = ""
    while line != Y:
        print step
        line += step
        if step > 0:
            step = -(step + 1)
            result += 'N'
        else:
            step = -step + 1
            result += 'S'
    if X * step > 0:
        step = -step
    while col != X:
        print step
        col += step
        if step > 0:
            step = -(step + 1)
            result += 'E'
        else:
            step = -step + 1
            result += 'W'
    assert len(result) < 500
    return result

f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    print test
    result = solve(f.readline().strip())
    out.write("Case #%s: %s\n" % (test, result))
out.close()
