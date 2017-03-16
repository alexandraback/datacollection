# -*- coding: utf-8 -*- 

fname = "C-small-attempt0"
fin = open(fname+".in","r")
fout = open(fname+".out","w")
def gcj_read():
  linestr = fin.readline().strip()
  return [int(numb) for numb in linestr.split()]


def is_palindrome(n):
    n = str(n)
    return n==n[::-1]

alldigits = [str(i) for i in range(10)]

def make_palindromes(length, digits=alldigits[1:]):
    if length == 1:
        for d in digits:
            yield d
    elif length == 2:
        for d in digits:
            yield d*2
    else:
        for d in digits:
            for subp in make_palindromes(length-2, digits=alldigits):
                yield d + subp + d

def make_fairsquares(rootlength, digits=alldigits):
    for palin in make_palindromes(rootlength, digits=digits):
        square = int(palin)**2
        lsq = ((rootlength-1)*2)+1
        square = str(square).rjust(lsq, '0')
        if is_palindrome(square):
            yield palin, square

def quick_fairsquares_even(rootlength):
    if rootlength == 2:
        for n in ['11', '22']:
            yield n
    else:
        half = (rootlength-2) //2
        for palin in quick_fairsquares_even(rootlength-2):
            for centredigits in ['00', '11', '22']:
                newpalin = palin[:half] + centredigits + palin[half:]
                if is_palindrome(int(newpalin)**2):
                    yield newpalin

def quick_fairsquares_odd(rootlength):
    if rootlength == 1:
        for n in ['1', '2']:
            yield n
    else:
        half = ((rootlength-2) //2)+1
        for palin in quick_fairsquares_odd(rootlength-2):
            for centredigit in ['0', '1', '2']:
                newpalin = palin[:half] + centredigit + palin[-half:]
                if is_palindrome(int(newpalin)**2):
                    yield newpalin

fairsquares = [1, 4, 9]
for rootlength in range(2,52):
    if rootlength % 2 == 0:
        it = quick_fairsquares_even(rootlength)
    else:
        it = quick_fairsquares_odd(rootlength)
    fairsquares.extend(int(i)**2 for i in it)

print('Generated %d fair squares' % len(fairsquares))

numcases = gcj_read()[0]

for caseno in range(numcases):
    A,B = gcj_read()
    
    count = 0
    for fs in fairsquares:
        if fs >= A:
            if fs > B:
                break
            else:
                count += 1
    
    outstr = str(count)
    print("Case #"+str(caseno+1)+": "+ outstr)
    fout.write("Case #"+str(caseno+1)+": "+ outstr +"\n")

fin.close()
fout.close()
