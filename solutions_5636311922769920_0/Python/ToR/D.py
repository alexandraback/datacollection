def solve(K, C, S):
    #small data (K==S)
    return " ".join([str(x+1) for x in range(S)])
    
def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    T = int(fin.readline().strip())
    
    for i in range(T):
        K,C,S = [int(x) for x in fin.readline().split()]
        result = solve(K, C, S)
        fout.write("Case #{:d}: {}\n".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("D-small-attempt0")