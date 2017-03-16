fin = open("../../Downloads/A-large (1).in", "r")
out = open("standing_ovation.out", "w")

cases = int(fin.readline())

for i in range(cases):
    d, shy = fin.readline().split()
    min = 0
    curr = 0
    for x in shy:
        curr += int(x)
        curr -= 1
        if curr < min:
            min = curr
    out.write("Case #%d: %d\n" % (i + 1, -min))
out.close()
