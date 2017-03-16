T = int(raw_input())

for i in xrange(T):
    print "Case #" + str(i + 1) + ":",

    B, M = list(map(int, raw_input().split()))

    if M > 2**(B-2):
        print "IMPOSSIBLE"
        continue
    else:
        print "POSSIBLE"

    binary = "{0:b}".format(M-1)
    if binary == "0":
        binary = ""

    #print "BINARY = ", binary
    print "0" + "0"*max(0, (B - 2 - len(binary))) + binary + "1" #("1" if M == 2**(B-2) else "0")

    for j in xrange(B-1):
        print "0"*(j+2) + "1"*(B-j-2)














