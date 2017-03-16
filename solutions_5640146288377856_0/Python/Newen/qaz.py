
fname = 'C:\Users\itocar\Downloads\A-small-attempt0.in'

f = open(fname)

ln = f.readlines()

t = int(ln[0])

for i,l in enumerate(ln[1:]):
    r,c,w = [int(q) for q in l.split()]
    res = 0
    res = (c + w -1)/w + w - 1
    res = res * r
    print 'Case #' + str(i+1) + ': ' + str(res)
