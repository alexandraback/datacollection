

def main():
    
    inf = open("small.in")
    outf = open("small.out", "w")
    
    nr = int(inf.readline())
    for tc in range(0, nr):
        tokens = inf.readline().split(" ")
        N = int(tokens[0])
        M = int(tokens[1])
        table = []
        for i in range(0, N):
            tokens = inf.readline().split(" ")
            row = []
            for token in tokens:
                row.append((int(token), False))
            table.append(row)
        
        answer = cutable(table, N, M)
        print("Case #%s: %s\n" % (str(tc+1), "YES" if answer else "NO"))
        outf.write("Case #%s: %s\n" % (str(tc+1), "YES" if answer else "NO"))
    

def print_table(table, N, M):
    for n in range(0, N):
        line = ""
        for m in range(0, M):
            line += str(table[n][m])
        print line
             
def cutable(table, N, M):
    for n in range(0, N):
        for m in range(0, M):
            if table[n][m][1]: 
                continue #already known right
            else:
                horizontal = is_horizontal_cut(table, N, M, n, m)                    
                vertical = is_vertical_cut(table, N, M, n, m)
                if not horizontal and not vertical:
                    return False
    return True
                                        


def is_vertical_cut(table, N, M, n, m):
    h = table[n][m][0]                
    for m2 in range(0, M):
        if table[n][m2][0] == h:
            pass #table[n2][m][1] = True #same cut
        elif table[n][m2][0] < h:
            pass # different non contradicting cut
        else: # different contradicting cut
            return False
    return True
                    

def is_horizontal_cut(table, N, M, n, m):
    h = table[n][m][0]                
    for n2 in range(0, N):
        if table[n2][m][0] == h:
            pass #table[n2][m][1] = True #same cut
        elif table[n2][m][0] < h:
            pass # different non contradicting cut
        else: # different contradicting cut
            return False;
    return True;

if __name__ == '__main__':
    main()