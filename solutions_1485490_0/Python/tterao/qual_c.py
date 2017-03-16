'''
Created on 2012/04/14

@author: teraotsuyoshi
'''

import copy

def is_exist(nl, n):
    for ls in nl:
        if ls[1] == n:
            return True
    return False

def get_max(nl_org, ml_org):
    nl = copy.deepcopy(nl_org)
    ml = copy.deepcopy(ml_org)
    
    if len(nl) == 0 or len(ml) == 0:
        return 0
    
    count = 0
    discarded = True
    while discarded:
        while len(nl) > 0 and len(ml) > 0 and nl[0][1] == ml[0][1]:
            mmin = min(nl[0][0], ml[0][0])
            count += mmin
            nl[0][0] -= mmin
            if nl[0][0] == 0:
                nl.pop(0)
            ml[0][0] -= mmin
            if ml[0][0] == 0:
                ml.pop(0)

        discarded = False                
        while len(nl) > 0 and not is_exist(ml, nl[0][1]):
            discarded = True
            nl.pop(0)
        
        while len(ml) > 0 and not is_exist(nl, ml[0][1]):
            discarded = True
            ml.pop(0)

    if len(nl) == 0 or len(ml) == 0:
        return count
    
    #  
    m_tmp = copy.deepcopy(ml[0])
    ml.pop(0)
    cm = get_max(nl, ml)

    ml.insert(0, m_tmp)
    nl.pop(0)

    cn = get_max(nl, ml)
    
    return count + max(cn, cm) 

if __name__ == '__main__':
    lines = open("C-small-attempt1.in").readlines()
    T = int(lines[0])
    
    li = 1
    for i in range(1, T+1):
        
        (N,M) = lines[li].split()
        N = int(N)
        M = int(M)
        
        nl = list()
        a = lines[li + 1].split()
        for n in range(N):
            nl.append([int(a[2*n]), int(a[2*n+1])])
        
        ml = list()
        a = lines[li + 2].split()
        for m in range(M):
            ml.append([int(a[2*m]), int(a[2*m+1])])
        

        count = get_max(nl, ml)

            
        
        
        print "Case #%d:"%(i), count
        
        li += 3
         
        
                