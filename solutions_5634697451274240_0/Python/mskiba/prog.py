t = int(raw_input())

for it in range(1, t + 1):
    line = raw_input()
    out = 0
    if line[0] == '-':
        out = 1
        line = line[1:]
    out += 2 * line.count('+-')
    print "Case #{}: {}".format(it, out)
