import math

def solve(line):
    r, t = (int(x) for x in line.split())
    delta = (2 * r + 3) * (2 * r + 3) - 8 * (2 * r + 1 - t)
    n = (- (2 * r + 3) + math.sqrt(delta)) / 4.0
    n = int(n)
    while 2 * n * n + n * (2 * r + 3) + 2 * r + 1 <= t:
        n += 1
    return n

f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    result = solve(f.readline().strip())
    out.write("Case #%s: %s\n" % (test, result))
out.close()
