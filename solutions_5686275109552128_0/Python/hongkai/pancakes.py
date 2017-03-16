fin = open("../../Downloads/B-small-attempt1.in", "r")
out = open("pancakes.out", "w")

cases = int(fin.readline())

for i in range(cases):
    d = int(fin.readline())
    list = [int(x) for x in fin.readline().split()]
    min = 1000
    for j in range(1, 1000):
        val = sum([(x-1)/j for x in list]) + j
        if val < min:
            min = val
    out.write("Case #%d: %d\n" % (i + 1, min))
out.close()
