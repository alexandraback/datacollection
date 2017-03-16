
fname = 'C:\Users\itocar\Downloads\C-large.in'

f = open(fname)

ln = f.readlines()

t = int(ln[0])

for i,l in enumerate(ln[1:]):
    if i % 2 == 0:
        c,d,v = [int(q) for q in l.split()]
    else:
        res = 0
        dn = [int(q) for q in l.split()]
        if dn[0] != 1:
            res = 1
            dn = [1] + dn
        cr = c
        for it in dn[1:]:
            if cr >= it - 1:
                cr = cr + c * it
            else:
                tmp = it
                while cr < tmp - 1:
                    res = res + 1
                    cr = cr + c  * (cr + 1)
                cr = cr + c * it
        while cr < v:
            res = res + 1
            cr = cr + c  * (cr + 1)
        print 'Case #' + str(i/2+1) + ': ' + str(res)
