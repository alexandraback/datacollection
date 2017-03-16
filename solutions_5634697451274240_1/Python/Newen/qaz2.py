f = open("C:\\Downloads\\B-large.in","r")
lines = f.readlines()
for i in range(1,int(lines[0])+1):
    cur = lines[i]
    groups = 0
    seen = False
    for c in cur:
        if c == '-':
            if not seen:
                seen = True
                groups += 1
        else:
            seen = False
    groups *= 2
    if cur[0] == '-':
        groups -= 1
    print "Case #" + str(i) + ": " + str(groups)