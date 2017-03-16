'''
Created on Apr 9, 2016

@author: tortor
'''
def solve(N):
    if N==0:
        return "INSOMNIA"
    
    digits = set()
    
    for i in range(1,100):
        t = N*i
        digits = digits.union(str(t))
                
        if len(digits)==10:
            return str(t)
    
    print("no result: {}".format(N))
    return "INSOMNIA"

def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    T = int(fin.readline().strip())
    
    for i in range(T):
        N = int(fin.readline().strip())
        result = solve(N)
        fout.write("Case #{:d}: {}\n".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("A-small-attempt0")