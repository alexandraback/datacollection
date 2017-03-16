'''
Created on Apr 9, 2016

@author: tortor
'''

def solve(plist):
    change = 0
    
    curr = plist[0]
    
    for p in plist[1:]:
        if curr != p:
            change += 1
            curr = p
    
    if plist[-1] == "-":
        change += 1
    
    
    return change

def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    N = int(fin.readline().strip())
    
    for i in range(N):
        plist = fin.readline().strip()
        result = solve(plist)
        fout.write("Case #{:d}: {:d}\n".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("B-small-attempt0")