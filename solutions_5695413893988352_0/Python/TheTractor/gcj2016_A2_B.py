#!/usr/bin/env python

def find_qm(s):
   return [k for k in xrange(len(s)) if s[k] == '?']

test_cases = int(raw_input())

for counter in xrange(1, test_cases+1):
    (C, J) = (raw_input().split(' '))
    
    loa_C = find_qm(C)
    loa_J = find_qm(J)
    
    if len(loa_C) > 0:
        C_template = '%0' + str(len(loa_C)) + 'd'
    else:
        C_template = ''
        
    if len(loa_J) > 0:
        J_template = '%0' + str(len(loa_J)) + 'd'
    else:
        J_template = ''
    
    total_template = '%0' + str(len(C)) + 'd'
    l_C = list(C)
    l_J = list(J)
        
    M = (1.1e18, -1, -1)
    for c_assignment in xrange(10 ** len(loa_C)):
        if C_template != '':
            for (u, d) in enumerate(C_template % c_assignment):
                l_C[loa_C[u]] = d
        val_C = int(''.join(l_C))
            
        for j_assignment in xrange(10 ** len(loa_J)):
            if J_template != '':
                for(u, d) in enumerate(J_template % j_assignment):
                    l_J[loa_J[u]] = d
            val_J = int(''.join(l_J))
            M = min(M, (abs(val_C - val_J), val_C, val_J))
    
    print 'Case #%d: %s %s' % (counter, total_template % M[1], total_template % M[2])
    