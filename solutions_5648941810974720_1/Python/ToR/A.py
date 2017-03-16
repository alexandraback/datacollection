def solve(S):
    result = []
    tmp = list(S)
    
    while "Z" in tmp:
        tmp.remove("Z")
        tmp.remove("E")
        tmp.remove("R")
        tmp.remove("O")
        result.append("0")
        
    while "W" in tmp:
        tmp.remove("T")
        tmp.remove("W")
        tmp.remove("O")
        result.append("2")
        
    while "U" in tmp:
        tmp.remove("F")
        tmp.remove("O")
        tmp.remove("U")
        tmp.remove("R")
        result.append("4")
        
    while "X" in tmp:
        tmp.remove("S")
        tmp.remove("I")
        tmp.remove("X")
        result.append("6")
        
    while "R" in tmp:
        tmp.remove("T")
        tmp.remove("H")
        tmp.remove("R")
        tmp.remove("E")
        tmp.remove("E")
        result.append("3")
        
    while "F" in tmp:
        tmp.remove("F")
        tmp.remove("I")
        tmp.remove("V")
        tmp.remove("E")
        result.append("5")
        
    while "V" in tmp:
        tmp.remove("S")
        tmp.remove("E")
        tmp.remove("V")
        tmp.remove("E")
        tmp.remove("N")
        result.append("7")
        
    while "H" in tmp:
        tmp.remove("E")
        tmp.remove("I")
        tmp.remove("G")
        tmp.remove("H")
        tmp.remove("T")
        result.append("8")
        
    while "O" in tmp:
        tmp.remove("O")
        tmp.remove("N")
        tmp.remove("E")
        result.append("1")
        
    while "N" in tmp:
        tmp.remove("N")
        tmp.remove("I")
        tmp.remove("N")
        tmp.remove("E")
        result.append("9")
        
    return "".join(sorted(result))
    
def main(fname):
    fin = open(fname+".in")
    fout = open(fname+".out","w")
    
    T = int(fin.readline().strip())
    
    for i in range(T):
        S = fin.readline().strip()
        result = solve(S)
        fout.write("Case #{:d}: {}\n".format(i+1,result))
    
    fin.close()
    fout.close()
    
if __name__ == '__main__':
    main("A-large")