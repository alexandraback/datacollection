def solve(line):
    r, t = (int(x) for x in line.split())
    count = 0
    while t >= (r + 1) * (r + 1) - r * r:
        count += 1
        t -= (r + 1) * (r + 1) - r * r
        r += 2
    return count

f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    result = solve(f.readline().strip())
    out.write("Case #%s: %s\n" % (test, result))
out.close()
