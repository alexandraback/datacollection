def gab_wins(line):
    x, r, c = [int(j) for j in line.split()]
    if c < r:
        r, c = c, r
    if (r*c) % x != 0:
        return False
    if x == 3 and r == 1:
        return False
    if x == 4 and (r <= 2 or c <= 3):
        return False
    if x == 5:
        if r > 3 and c > 4:
            return True
        if r == 3 and c > 6:
            return True
        return False
    if x == 6 and (r <= 3 or c <= 5):
        return False
    if x > 6:
        return False
    return True

fin = open("../../Downloads/D-large.in", "r")
out = open("ominous_omino.out", "w")

cases = int(fin.readline())

for i in range(cases):
    out.write("Case #%d: %s\n" % (i + 1, "GABRIEL" if gab_wins(fin.readline()) else "RICHARD"))
out.close()
