'''
Created on May 2, 2015

@author: sshadmin
'''
from itertools import product

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count
def solve(k,l,s,board,target):
    gen=list(product(board, repeat = s))
    sm=0
    mx=0
    for word in gen:
        x="".join(word)
        tmp=occurrences(x,target)
        mx=max(mx,tmp)
        sm+=tmp
    return mx-sm/float(len(gen))
        
    

fin=open('in','r') ; fout=open('out','w')
cases=int(fin.readline().strip())
for case in range(1,cases+1):
    k,l,s=[int(x) for x in fin.readline().strip().split()]
    board=list(fin.readline().strip())
    target=fin.readline().strip()
    print case
    fout.write("Case #"+str(case)+": "+str(solve(k,l,s,board,target))+"\n")
    
    