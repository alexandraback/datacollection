f = open("C:\\Downloads\\A-small-attempt0.in","r")
lines = f.readlines()

for i in range(1,int(lines[0])+1):
    cur = int(lines[i])
    if cur == 0:
        print "Case #" + str(i) + ": INSOMNIA"
    else:
        j = cur
        seen = []
        while True:
            for c in str(j):
                if c not in seen:
                    seen.append(c)
            if len(seen) == 10:
                print "Case #" + str(i) + ": " + str(j)
                break
            j += cur