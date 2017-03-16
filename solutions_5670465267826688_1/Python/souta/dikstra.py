import math

def calc(lsign, l, rsign, r):
    calcdict = {'11':'1', '1i':'i', '1j':'j', '1k':'k',
                'i1':'i', 'ii':'1', 'ij':'k', 'ik':'j',
                'j1':'j', 'ji':'k', 'jj':'1', 'jk':'i',
                'k1':'k', 'ki':'j', 'kj':'i', 'kk':'1'}
    signdict = {'11':0, '1i':0, '1j':0, '1k':0,
                'i1':0, 'ii':1, 'ij':0, 'ik':1,
                'j1':0, 'ji':1, 'jj':1, 'jk':0,
                'k1':0, 'ki':0, 'kj':1, 'kk':1}
    sign = (lsign + rsign + signdict[l+r]) % 2
    return [sign, calcdict[l+r]]

fin = open('C-large.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    [l, x] = [int(i) for i in fin.readline().split()]
    line = fin.readline()
    result = 'NO'
    ornd = '1'
    orndsign = 0
    for i in range(0, l):
        [orndsign, ornd] = calc(orndsign, ornd, 0, line[i])
    total = '1'
    totalsign = 0
    for i in range(0, x % 4):
        [totalsign, total] = calc(totalsign, total, orndsign, ornd)
    #fout.write(total + ' ' + str(totalsign) + '\n')
    if (totalsign == 1 and total == '1'):
        loopi = 0
        indexi = -1
        temp = '1'
        tempsign = 0
        while (loopi < 4 and not(temp == 'i' and tempsign == 0)):
            indexi += 1
            if indexi == l:
                indexi = 0
                loopi += 1
            [tempsign, temp] = calc(tempsign, temp, 0, line[indexi])
        loopk = 0
        indexk = l
        temp = '1'
        tempsign = 0
        while (loopk < 4 and not(temp == 'k' and tempsign == 0)):
            indexk -= 1
            if indexk == -1:
                indexk = l - 1
                loopk += 1
            [tempsign, temp] = calc(0, line[indexk], tempsign, temp)
        #fout.write(str(loopi) + ' ' + str(indexi) + ' '+str(loopk) + ' ' + str(indexk) + '\n')
        if loopi < 4 and loopk < 4 and loopi + loopk < x:
            if loopi + loopk < x - 1:
                result = 'YES'
            elif indexi < indexk:
                result = 'YES'
    fout.write('Case #'+str(count)+': '+ result +'\n')
fin.close()
fout.close()
