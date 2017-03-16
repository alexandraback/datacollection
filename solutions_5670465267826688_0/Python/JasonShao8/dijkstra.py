t = input()
hacks = {}
hacks['11'] = '1'
hacks['1i'] = 'i'
hacks['1j'] = 'j'
hacks['1k'] = 'k'
hacks['i1'] = 'i'
hacks['ii'] = '-1'
hacks['ij'] = 'k'
hacks['ik'] = '-j'
hacks['j1'] = 'j'
hacks['ji'] = '-k'
hacks['jj'] = '-1'
hacks['jk'] = 'i'
hacks['k1'] = 'k'
hacks['ki'] = 'j'
hacks['kj'] = '-i'
hacks['kk'] = '-1'

for poo in range(t):
    l, x = map(int, raw_input().split())
    s = raw_input()
    s = s*x

    if len(s) < 3:
        print "Case #" + str(poo + 1) + ": NO"
        continue

    seeni = False
    seenj = False
    seenk = False

    neg = 0 
    ans = s[0]

    for i in s[1:]:
        if neg == 0 and ans == 'i' and seeni == False:
            seeni = True
            ans = '1'
        elif neg == 0 and seeni and ans == 'j' and seenj == False:
            seenj = True
            ans = '1'

        temp = hacks[ans + i]
        if len(temp) > 1:
            neg ^= 1 
            ans = temp[1]
        else:
            ans = temp

    if neg == 0 and seeni and seenj and ans == 'k':
        print "Case #" + str(poo + 1) + ": YES"
    else:
        print "Case #" + str(poo + 1) + ": NO"
       


