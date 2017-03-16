con = "bcdfghjklmnpqrstvwxyz"

for TC in range(1, input()+1):
    name, n = raw_input().split()
    n = int(n)
    count = 0
    for length in range(n, len(name)+1):
        for start in range(len(name)-length+1):
            substring = name[start:start+length]
            highest = 0
            consec = 0
            for c in substring:
                if c in con:
                    consec += 1
                else:
                    consec = 0
                if consec > highest:
                    highest = consec
            if highest >= n:
                count += 1
    print "Case #%d: %d" % (TC, count)