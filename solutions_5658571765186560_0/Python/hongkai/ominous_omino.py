fin = open("../../Downloads/D-small-attempt0 (1).in", "r")
out = open("ominous_omino.out", "w")

cases = int(fin.readline())

for i in range(cases):
    x, r, c = [int(j) for j in fin.readline().split()]
    ans = True
    if (r*c) % x != 0:
        ans = False
    if x == 4 and r*c < 12:
        ans = False
    if x == 3 and (r == 1 or c == 1):
        ans = False
    out.write("Case #%d: %s\n" % (i + 1, "GABRIEL" if ans else "RICHARD"))
out.close()
