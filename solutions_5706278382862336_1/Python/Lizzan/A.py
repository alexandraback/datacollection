"""Code written using Python 2.7.5, http://www.python.org/"""

from fractions import Fraction

def checkPow2(num):
    return num != 0 and ((num & (num - 1)) == 0)

def calc(case):
    (a, b) = [int(e) for e in case.split('/')]

    #print a, b

    frac = Fraction(a, b)

    #print frac

    #print checkPow2(frac.denominator)


    if not checkPow2(frac.denominator):
        return "impossible"
    
    count = 0
    num = frac.numerator
    den = frac.denominator
    while num / den < 0.5:
        den = den / 2
        count += 1
        

    return str(count)
	
		
		

f = open('A-large.in', 'r')
lines = f.readlines()
f.close()
c = lines[0].split()[0]
#print c
lines = [r.strip() for r in lines[1:]]
#print cases

of = open('output_a_large.txt', 'w')

for idx, case in enumerate(lines):
    of.write('Case #%(idx)i: %(i)s\n' % {'idx': idx + 1, 'i': calc(case)})

of.close()
