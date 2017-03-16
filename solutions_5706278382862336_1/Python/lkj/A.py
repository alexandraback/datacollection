#inp: fraction of how much elf she is
#outp: min number of gens ago that she could have had a fullblood elf in her family

#ideas: you can always subtract the max 1/2**x below p/q
#   -> the x is the solution
#   -> we have to analyse the rest of the fraction to see
#       if it's even possible if 40 gens ago there were only 1/1 and 0/1 elves
#   -> if it is, print x from above
#   -> if not print impossible

#she's not a 1/1 elf (p < q)

from fractions import Fraction

def impo(tc):
    print('Case #%i: impossible' % (tc))

def resu(tc, r):
    print('Case #%i: %i' % (tc, r))

def getmaxp2(frac):
    x = 1
    while x < 41:
        if Fraction(1, 2**x) <= pqfrac:
            break
        x += 1
    return x

t = int(input())
for tc in range(1, t+1):
    pqfrac = Fraction(input())
    
    x = getmaxp2(pqfrac)
    if x == 41:
        impo(tc)
        continue
    
    pqfrac -= Fraction(1, 2**x)
    while pqfrac != 0:
        tmp = getmaxp2(pqfrac)
        if tmp == 41:
            break
        pqfrac -= Fraction(1, 2**tmp)

    if pqfrac == 0:
        resu(tc, x)
    else:
        impo(tc)
