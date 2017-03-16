import math


#num_row = raw_input()
#num_row = int(num_row.strip())
"""
s = 'HELLO'
s = s[0:len(s)-1] + s[::-1]
print s
"""
rd = open('C-large-1.in',"r")
#rd = open('C-large-1.in',"r")
cmd = rd.readlines()
cmd = [ fuq.strip() for fuq in cmd ]
num_row = int(cmd[0])

for rnd in range(num_row):
    s = cmd[rnd+1]
    s = [long(x.strip()) for x in s.split(' ')]
    p = long(math.ceil(math.sqrt(s[0])))
    lim = long(math.floor(math.sqrt(s[1])))
    cnt =0
    pt = long(p)
    sp = str(pt)
    sp_num = int(math.ceil(len(sp)/2.0))
    sp = sp[:sp_num]
    pt = long(sp)
    sp = str(long(lim))
    sp_num = int(math.ceil(len(sp)/2.0))
    sp = sp[:sp_num]
    pt = min(pt,long(sp))
    lst = []
    pt = 10**(int(math.ceil(len(str(p))/2.0))-1)

#    print p,lim
    while True:
        sp = str(pt)
        pal1 = sp[0:len(sp)-1] + sp[::-1]
        pal2 = sp + sp[::-1]
#        print sp,'>>',pt,':',pal1,':',pal2
        pal1 = long(pal1)
        if pal1 > lim: break
        if pal1 >= p:
            dbt = long(pal1**2)
            dbs = str(dbt)
            if dbs == dbs[::-1]:
#                print pal1
                cnt+=1
        pal2 = long(pal2)
        if pal2 <= lim and pal2 >= p:
            dbt = long(pal2**2)
            dbs = str(dbt)
            if dbs == dbs[::-1]:
#                print pal2
                cnt+=1
        pt+=1
    print "Case #%d: %d"%(rnd+1,cnt)
#    print "Case #%d: %d"%(rnd+1,cnt)
