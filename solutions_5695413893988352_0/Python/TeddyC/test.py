# f = open('A-large-practice.in')
f = open('B-small-attempt0.in')

import sys
sys.stdout = open('out', 'w')


DL = range(10)
DL = [str(i) for i in DL]

def replace(ll):
    item = ""
    idx = 0
    notfound = True
    for item in ll:
        idx = 0
        for char in list(item):
            if char == '?':
                notfound = False
                break
            idx += 1
        if not notfound:
            break
        
    if notfound:
        return True
    
    for d in DL:
        
        temp = list(item)
#         print temp, idx,d 
        temp[idx] = d
        ll.append(''.join(temp))
#         print temp, idx,d, ll
        
    ll.remove(item)
#     print ll
    return False


T = f.readline()
for case in range(int(T)):
    l = f.readline().split()
    coder = 0
    jammer = 0
    clist = [l[0]]
    jlist = [l[1]]

    while not replace(clist):
        pass
    while not replace(jlist):
        pass
    
    clist = sorted(clist)
    jlist = sorted(jlist)
    
#     print clist
#     print jlist
    
#     idxC = 0
#     idxJ = 0
    minC = "" 
    minJ = ""
    mindiff = 9999999999999999999
    
    for cc in clist:
        for jj in jlist:
            diff = abs(int(cc)-int(jj))
#             print cc,jj,diff
            if diff < mindiff:
                mindiff = diff
                minC = cc
                minJ = jj
    
    print "Case #"+str(case+1)+":", str(minC), str(minJ)
    
