def solve(nlist):
    
    N = len(nlist)
    alist = [x[0] for x in nlist]
    blist = [x[1] for x in nlist]
    
    a = len(set(alist))
    b = len(set(blist))
        
    return N-max(a,b)

   
def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    T = int(fin.readline().strip())
    
    for i in range(T):
        N = int(fin.readline().strip())
        nlist = []
        for j in range(N):
            nlist.append(fin.readline().split())
        
        result = solve(nlist)
        fout.write("Case #{:d}: {}\n".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("C-small-attempt0")