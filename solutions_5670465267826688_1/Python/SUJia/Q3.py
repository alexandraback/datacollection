import numpy as np
      
mydict = {}
mydict[('1', '1')] = (1, '1')   
mydict[('1', 'i')] = (1, 'i')
mydict[('1', 'j')] = (1, 'j')
mydict[('1', 'k')] = (1, 'k')
mydict[('i', '1')] = (1, 'i')                
mydict[('i', 'i')] = (-1,'1')  
mydict[('i', 'j')] = (1, 'k') 
mydict[('i', 'k')] = (-1,'j') 
mydict[('j', '1')] = (1, 'j')  
mydict[('j', 'i')] = (-1,'k')   
mydict[('j', 'j')] = (-1,'1') 
mydict[('j', 'k')] = (1, 'i') 
mydict[('k', '1')] = (1, 'k')
mydict[('k', 'i')] = (1, 'j')
mydict[('k', 'j')] = (-1,'i')
mydict[('k', 'k')] = (-1,'1')

def ijkMultiply( val1, str1 ):
    if len(str1) == 0:
        return 1, '1'
    elif len(str1) == 1:
        return val1, str1
    else:
        val, letter = mydict[(str1[0], str1[1])]
        return ijkMultiply( val * val1, letter + str1[2:])

f = open('C-large.in.txt', 'r')
fr = open('C-large.out.txt', 'w')
#f = open('input', 'r')
#fr = open('output', 'w')
line = f.readline()
ntot = int(line.split()[0])
for i in range(ntot):
    line1 = f.readline()
    L, X = map(int, line1.split()[:2])
    line2 = f.readline()
    strshort = line2.split()[0]
    strlong = strshort*4
#    print L, X, strshort
    #flist = []
    #elist = []
        
    lpos, rpos = -1, -1
    llet, rlet = strlong[0], strlong[4*L-1]
    lval, rval = 0, 0
    for j in range(1, 4*L):
        if llet == 'i':
            lpos = j
            break
        lval, llet = mydict[(llet, strlong[j])]
    for j in range(4*L-2, -1, -1):
        if rlet == 'k':
            rpos = j+1
            break
        rval, rlet = mydict[(strlong[j], rlet)]
#    print 'lpos: ',lpos,'    rpos: ',rpos,'\n'
        
    existStriBeforeStrj = False
    if lpos != -1 and rpos != -1:
        if lpos < (rpos + (X-4) * L):
            existStriBeforeStrj = True 

    wholeStrEqualMinusOne = False
    mval, mlet = 1, '1'
    for j in range(L):
        mvalt, mlet = mydict[(mlet, strlong[j])] 
        mval = mval * mvalt
    if mlet == '1': 
        if mval == -1 and X%2 == 1:
            wholeStrEqualMinusOne = True
    else:
        if X%4 == 2:
            wholeStrEqualMinusOne = True            
                                    
    #for j in range(4*L + 1):
    #    flist.append(ijkMultiply(1, str4[:j]))
    #    elist.append(ijkMultiply(1, str4[j:]))        
    # pos 0 -- pos n1, string1, to i
    # pos n1 -- pos n2, string2, to j
    # pos n2 -- pos L*X, string3, to k
    #for n1 in range(1,L*X-1):
    #    n1r = n1 % (4*L)
    #    val1, let1 = ijkMultiply(1, strlong[:n1r])
    #    if let1 == 'i' and val1 == 1:
    #        for n2 in range(n1+1, L*X):
    #            n2r = (n2 - n1) % (4*L) + n1r
    #            val2, let2 = ijkMultiply(1, strlong[n1r:n2r])  
    #            if let2 == 'j' and val2 == 1:
    #                n2r = n2 % (4*L)
    #                n3r = (X*L - n2) % (4*L) + n2r
    #                val3, let3 = ijkMultiply(1, strlong[n2r:n3r]) 
    #                if let3 == 'k' and val3 == 1:
    #                    res = True
    #                    print 'True'
    #                    break
    #                else:
    #                    continue
    #            else: 
    #                continue
    #        if res == True:
    #            break
    #    else: 
    #        continue              
    if existStriBeforeStrj == True and wholeStrEqualMinusOne == True:
        fr.write('Case #'+ str(i+1) + ': YES\n')
    else:
        fr.write('Case #'+ str(i+1) + ': NO\n')
f.close()
fr.close()