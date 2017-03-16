
f = open('A-small-attempt0.in', 'r')
o = open('out.txt', 'w')
T = f.readline()
T = int(T)
for t in range(1, T+1):
    s = f.readline()
    s = s.split()
    s = map(int, s)
    r = s[0]
    c = s[1]
    w = s[2]
    
    ans = (c//w) * r
    if (c % w == 0):
        ans += w -1
    else:
        ans += w
                     
    outline = "Case #%d: %d\n" % (t, ans)
    o.write(outline)

o.close()
