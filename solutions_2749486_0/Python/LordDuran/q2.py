inputfile = file("B-small.in", "rb")
outputfile = file("output.out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]

T = int(inputfile.readline())
    
def abs(t):
    if t > 0:
        return t
    return -t
    
print "%d cases" % T
for ncase in xrange(1,T+1):
    x, y = parse_line()    
    k = 0
    cur_x, cur_y = 0, 0
    s = ''
    while 1:
        k += 1
        if cur_x + k <= abs(x):
            s += 'E'
            cur_x += k
            continue
        if cur_y + k <= abs(y):
            s += 'N'
            cur_y += k
            continue
        break
    s += 'WE' * (abs(x) - cur_x)
    s += 'SN' * (abs(y) - cur_y) 
    
    if x < 0:
        s = s.replace("W", "X")
        s = s.replace("E", "W")
        s = s.replace("X", "E")
    if y < 0:
        s = s.replace("S", "X")
        s = s.replace("N", "S")
        s = s.replace("X", "N")
    print out_s % (ncase, s )
    print >>outputfile, out_s % (ncase, s)