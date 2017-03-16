"""Bullseye"""

infile = open("A-small-attempt0.in", "r")
outfile = open("A.out", "w")
lines = infile.read().split("\n")
T = int(lines[0])
for i in range(1, T + 1):
    line = lines[i].split()
    r = int(line[0])
    t = int(line[1])
    low = 1
    high = 1000000000
    while (low <= high):
        mid = (low + high) / 2
        val = mid * (2 * mid + 2 * r - 1)
        if t > val:
            low = mid + 1
        elif t < val:
            high = mid - 1
        else:
            break
    if high < low:
        n = high
    else:
        n = mid
    outfile.write("Case #" + str(i) + ": " + str(n) + "\n")
infile.close()
outfile.close()
