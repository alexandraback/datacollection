'''
Created on Apr 9, 2016

@author: tortor
'''
import math

def solve(N, J):
    results = {}
    n = int("1"+("0"*(N-2))+"1",2)
    while len(results)<J:
        tstr =  "{:b}".format(n)
        flist = []
        isPrime = False
        for base in range(2,10+1): #base2 - 10
            tnum = int(tstr, base)
            factor = leastFactor(tnum)
            print("{} base {}= {} factor={}".format(tstr,base,int(tstr,base),factor))
            if factor == tnum:
                isPrime = True
                break
            else:
                flist.append(str(factor))
        if not isPrime:
            results[tstr] = flist
            
        n += 2
        
    return format_results(results)
             
def format_results(results):
    s = ""
    for k in results.keys():
        s += "{} {}\n".format(k," ".join(results[k]))
        
    return s
        
        
def leastFactor(n):
    
    if n==0 or n==1: return n
    if n%2==0: return 2
    if n%3==0: return 3
    if n%5==0: return 5
    if n%7==0: return 7
    m = int(math.sqrt(n))
    for i in range(11,m+1,30):
        if n % i == 0: return i;
        if n % (i + 4) == 0:  return i + 4;
        if n % (i + 6) == 0:  return i + 6;
        if n % (i + 10) == 0: return i + 10;
        if n % (i + 12) == 0: return i + 12;
        if n % (i + 16) == 0: return i + 16;
        if n % (i + 22) == 0: return i + 22;
        if n % (i + 24) == 0: return i + 24;
    return n

def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    T = int(fin.readline().strip())
    
    for i in range(T):
        N, J = [int(x) for x in fin.readline().split()]
        result = solve(N, J)
        fout.write("Case #{:d}:\n{}".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("C-small")
