'''
Created on 2014-4-26

@author: ezonghu
'''
'''
Created on Apr 25, 2014

@author: ezonghu
'''

def solve(P, Q):
    if P == Q:
        return 0
    
    if Q % 2 != 0:
        return "impossible"
    newQ = Q / 2 
    if P > newQ:
        if solve(P-newQ, newQ) != "impossible":
            return 1
        return "impossible"
    
    res = solve(P, newQ)
    if res != "impossible":
        return 1 + res
    return res
        

fn="C:/Users/ezonghu/Downloads/A-large"
fi=open(fn+'.in')
fo=open(fn+'.out','w')
Cases = int(fi.next())
CaseId = 0
   
for l in fi:
    [P, Q] = [int(i) for i in l.split("/")]
    res = solve(P,Q)
    CaseId += 1
    Output = "Case #%d: %s" % (CaseId, res)
    print Output
    fo.write(Output+'\n')
    if Cases == CaseId:
        break
fi.close()
fo.close()