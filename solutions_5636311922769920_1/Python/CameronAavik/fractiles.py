import math

file = open('D-large.in', 'r')
out_file = open('output_file.txt', 'w')
amount = file.readline()
for i in range(int(amount)):
    k, c, s = file.readline().strip().split()
    k, c, s = int(k), int(c), int(s)
    output = ""
    if math.ceil(k/c) > s:
        output = "IMPOSSIBLE"
    else:
        l = list(range(1, k + 1))
        indexes = [l[i:i+c] for i in range(0, len(l), c)]
        positions = []
        for idx in indexes:
            pos = 0
            idx = idx[::-1]
            for j, offset in enumerate(idx):
                pos += (k**j)*(offset-1)
            positions += [pos + 1]
        output = ' '.join(str(n) for n in positions)
    out_file.write("Case #" + str(i + 1) + ": " + output + "\n")

file.close()
out_file.close()
