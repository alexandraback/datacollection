f = open('A-large.in')
# f = open('test.in')

import sys
sys.stdout = open('out', 'w')

T = f.readline()
WL = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
# u 4, z 0, x 6, w 2, v 75, 

def contains(w, l):
    temp=[]
    for c in w:
        if c in l and w.count(c) <= l.count(c):
            temp.append(c)   
    if sorted(w) == sorted(temp):
        return True
    return False

def findUnique(a,b,d,l,phone): 
    while l.count(a) != 0:
        for c in list(b):
            l.remove(c)
        phone.append(d)

for case in range(int(T)):
    orig = list(f.readline())
    l = list(orig)
#     skipCount = 0
#     while len(l) != 0:
#         l = list(orig)
    phone = []
    idx = 0
#     skipCountTemp = skipCount
    
    findUnique("Z","ZERO","0",l,phone)
    findUnique("W","TWO","2",l,phone)
    findUnique("U","FOUR","4",l,phone)
    findUnique("X","SIX","6",l,phone)
#     while l.count("U") != 0:
#         for c in list("FOUR"):
#             l.remove(c)
#         phone.append("4")
        
    while idx < 10:
        w = list(WL[idx])
        if contains(w, l):
            phone.append(str(idx))
            for c in w:
                l.remove(c)
        else:
            idx += 1
#         skipCount += 1
    if len(l) != 1:
        print l
    res = ''.join(sorted(phone))
        
         
    print "Case #"+str(case+1)+":", res
    
