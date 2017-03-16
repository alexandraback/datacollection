from fractions import Fraction
import math

anc = 2**40

def sol():
    def rec(_dec):
        _f = Fraction.from_float(_dec)
        if _dec>=0.5:
            return 1
        if (_f.numerator==1):
            return int(math.log(_f.denominator,2))
        return 1+rec(_dec*2-(1/_f.denominator))
    global line_counter
    p,q = inp[line_counter].split('/')
    line_counter+=1
    P = int(p)
    Q = int(q)
    dec = float(P)/float(Q)
    f = Fraction.from_float(dec)
    print f
    if (f.denominator%2==0 and f.denominator<= anc):
        denom_power = None
        for i in range(1,41):
            if (f.denominator==(2**i)):
                denom_power = i
                break
        if denom_power==None:
            return 'impossible'
        return str(rec(dec))
        
    else:
        return 'impossible'
##    check = (float(p)/float(q))*(anc)
##    if (check%1==0):
##        pass
##    else:
##        return 'impossible'

with open('A-large (1).in', 'r') as f:
#with open('LOL.txt', 'r') as f:
    inp = f.readlines()
    f.close()
line_counter = 0
T = int(inp[line_counter])
line_counter+=1
data = ''
for i in range(T):
    data += 'Case #%d:' %(i+1) + ' ' + sol()+'\n'
with open('output.txt', 'w') as f:
    f.write(data)
    f.close()
#print data
print 'done!'
