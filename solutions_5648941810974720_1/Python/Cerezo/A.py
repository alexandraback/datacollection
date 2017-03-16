from math import sqrt
from scipy.misc import comb #use comb(n,k,True)

def Next(S):
    dic = {}
    for x in list('ABCDEFGHIJKLMNOPQRSTUVWXYZ'):
        dic[x] = 0
    for s in S:
        dic[s] += 1
    digits = []
    d = dic['Z']
    dic['E'] -= d
    dic['R'] -= d
    dic['O'] -= d
    digits.extend(d*[0])
    
    d = dic['W']
    dic['T'] -= d
    dic['O'] -= d
    digits.extend(d*[2])

    d = dic['U']
    dic['F'] -= d
    dic['O'] -= d
    dic['R'] -= d
    digits.extend(d*[4])


    d = dic['X']
    dic['S'] -= d
    dic['I'] -= d
    digits.extend(d*[6])


    d = dic['G']
    for x in 'EIHT':
        dic[x] -= d
    digits.extend(d*[8])

    d = dic['O']
    for x in 'NE':
        dic[x] -= d
    digits.extend(d*[1])

    d = dic['R']
    for x in 'THEE':
        dic[x] -= d
    digits.extend(d*[3])

    d = dic['F']
    for x in 'IVE':
        dic[x] -= d
    digits.extend(d*[5])

    d = dic['S']
    for x in 'EVEN':
        dic[x] -= d        
    digits.extend(d*[7])

    d = dic['I']
    digits.extend(d*[9])

    digits.sort()
        
    return ''.join(str(i) for i in digits)
        

#input = open(r'sample.in')
#input = open(r'A-small-attempt0.in')
input = open(r'A-large.in')

T = int(input.readline())

sol = []

for i in xrange(T):
    S = input.readline().strip()
    sol += [Next(S)]
    if not i%10: print i


tofile = True
if tofile:
    with open(r'./outputA-L.txt', 'w') as output:
        for i in range(len(sol)):
            output.write('Case #%s: %s\n' % (i+1, sol[i]))
else:
    print sol


