from decimal import *
def quad(a,b,c):
   root=b**2-4*a*c
   if root >= 0:
       x1=(-Decimal(b)+Decimal(root).sqrt())/(Decimal(2)*Decimal(a))
       x2=(-Decimal(b)-Decimal(root).sqrt())/(Decimal(2)*Decimal(a))
       return x1,x2
   else:
       return 0, 0


fin = file('input.txt', 'r')
fout = file('output.txt', 'w')

T = int(fin.readline().strip())
for i in range(0, T):
    sp = fin.readline().split()
    r = int(sp[0])
    t = int(sp[1])

    a = 2
    b = 0
    if r % 2 == 0:
        b = 4*(r/2 - 1) + 3
    else:
        b = 4*((r-1)/2) + 1
    c = -t

    getcontext().prec = 1000

    results = quad(a, b, c)
    if results[0] >= 1:
        fout.write('Case #%d: %d\n' % (i + 1, int(results[0])))
    else:
        fout.write('Case #%d: %d\n' % (i + 1, int(results[1])))





fin.close()
fout.close()
