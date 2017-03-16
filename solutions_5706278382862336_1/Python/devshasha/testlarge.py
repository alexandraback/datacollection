def gcd(x,y):
    if y==0:
	    return x
    else:
	    return gcd(y, x%y)

test = int(raw_input())
count = 1
impossible = False
while test > 0:
    fraction = raw_input()
    inp = fraction.split("/")
    g = gcd(int(inp[0]), int(inp[1]))
    inp[0] = ( float(inp[0])/float(g) )
    inp[1] = ( float(inp[1])/float(g) )
    a = inp[0] / inp[1]
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
