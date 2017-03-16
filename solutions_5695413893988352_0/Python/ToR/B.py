def solve(C,J):
    print(C,J)
    l=len(C)
    
    minC = int(C.replace("?","0"))
    maxC = int(C.replace("?","9"))
    minJ = int(J.replace("?","0"))
    maxJ = int(J.replace("?","9"))
    
    diff = 999
    rc = minC
    rj = minJ
    stop = False
    
    for c in range(minC, maxC+1):
        for j in range(minJ, maxJ+1):
            #break on equal
            if diff == 0:
                return format_num(rc, l)+" "+format_num(rj, l)
            
            if diff > abs(c-j):
                if format_check(c, C) and format_check(j, J):
                    diff = abs(c-j)
                    rc = c
                    rj = j
        
    return format_num(rc, l)+" "+format_num(rj, l)

def format_check(n, N):
    tn = format_num(n, len(N))
    
    for i,c in enumerate(N):
        if c!="?" and tn[i] != c: 
            return False
        
    return True

def format_num(n, l):
    f = "{:0"+str(l)+"}"
    return f.format(n)
    
def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    T = int(fin.readline().strip())
    
    for i in range(T):
        C, J = fin.readline().split()
        result = solve(C, J)
        fout.write("Case #{:d}: {}\n".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("B-small-attempt1")