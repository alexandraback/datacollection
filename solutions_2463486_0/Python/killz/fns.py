import math


#num_row = raw_input()
#num_row = int(num_row.strip())

rd = open('C-small.in',"r")
cmd = rd.readlines()
cmd = [ fuq.strip() for fuq in cmd ]
num_row = int(cmd[0])

for rnd in range(num_row):
    s = cmd[rnd+1]
    s = [long(x.strip()) for x in s.split(' ')]
    x = long(math.ceil(math.sqrt(s[0])))
    lim = long(math.floor(math.sqrt(s[1])))
    cnt =0
    while x <= lim:
        chk = 0
        s = str(x)
        sp = s[::-1]
        if s != sp:
            x += 1
            continue
        xp = long(x**2)
        z = str(xp)
        zp = z[::-1]
        if s == sp and z == zp:
            cnt += 1
        x += 1
    print "Case #%d: %d"%(rnd+1,cnt)
