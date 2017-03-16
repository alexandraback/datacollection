test = int(raw_input())
count = 1
impossible = False
while test > 0:
    fraction = raw_input()
    inp = fraction.split("/")
    a = float(inp[0]) / float(inp[1])
    if int(inp[1]) & int(inp[1])-1 != 0:
        impossible = True
    gen = 1
    while a * 2 < 1:
        a = a * 2
        gen += 1
    if impossible == True:
        print "Case #" + str(count) + ": impossible"
    else:
        print "Case #" + str(count) + ": " + str(gen)
    impossible = False
    test -= 1
    count += 1