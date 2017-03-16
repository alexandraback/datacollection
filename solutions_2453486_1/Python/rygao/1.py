def xwin(l):
    if ('.' in l) or ('O' in l):
        return False
    else:
        return True
    
def owin(l):
    if ('.' in l) or ('X' in l):
        return False
    else:
        return True


f = open('A-large.in', 'r')
T = f.readline().strip()
T = int(T)

g = open('output-large.txt', 'w')

print T
for i in xrange(T):
    a = f.readline().strip()
    b = f.readline().strip()
    c = f.readline().strip()
    d = f.readline().strip()
    a1 = a[0]+b[0]+c[0]+d[0]
    b1 = a[1]+b[1]+c[1]+d[1]
    c1 = a[2]+b[2]+c[2]+d[2]
    d1 = a[3]+b[3]+c[3]+d[3]
    diag1 = a[3]+b[2]+c[1]+d[0]
    diag2 = a[0]+b[1]+c[2]+d[3]

    if xwin(a) or xwin(b) or xwin(c) or xwin(d) or xwin(diag1) or xwin(diag2) or xwin(a1) or xwin(b1) or xwin(c1) or xwin(d1):
        g.write('Case #%d: X won\n' % (i+1))
    elif owin(a) or owin(b) or owin(c) or owin(d) or owin(diag1) or owin(diag2) or owin(a1) or owin(b1) or owin(c1) or owin(d1):
        g.write('Case #%d: O won\n' % (i+1))
    elif ('.' in a) or ('.' in b) or ('.' in c) or ('.' in d):
        g.write('Case #%d: Game has not completed\n' % (i+1))
    else:
        g.write('Case #%d: Draw\n' % (i+1))

    f.readline()


f.close()
g.close()
