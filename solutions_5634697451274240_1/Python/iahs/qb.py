import sys
ncases = int(raw_input())
for case in range(ncases):
    s = raw_input()
    nflips = 0
    happy = s[0] == '+'
    last = s[0]
    for i in s:
        if i != last:
            last = i
            nflips += 1
    nflips += (nflips%2) == happy
    print "Case #%d: %d" % (case+1, nflips)
