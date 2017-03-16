
def check(t):
    ans = ""
    if t.count('X') == 4:
        ans = "X"
    elif t.count('X') == 3 and t.count('T') == 1:
        ans = "X"
    elif t.count('O') == 4:
        ans = 'O'
    elif t.count('O') == 3 and t.count("T") == 1:
        ans = 'O'

    return ans

if __name__ == '__main__':
    lines = open("A-small-attempt0.in").readlines()
    T = int(lines[0])
    ln = 1

    for i in range(1, T+1):
        ongoing = False
        t = []
        for j in range(4):
            cols = list()
            for x in lines[ln].strip():
                cols.append(x)
                if x == '.':
                    ongoing = True
            t.append(cols)
            ln = ln + 1
            
        #        print t
        ln = ln + 1 # skip empty line

        ans = ""
        for row in t:
            ans = check(row)
            if ans != "":
                break
        
        if ans == "":
            for c in range(4):
                col = list()
                for r in range(4):
                    col.append(t[r][c])
                
                ans = check(col)
                if ans != "":
                    break
        
        if ans == "":
            diag = [ t[0][0], t[1][1], t[2][2], t[3][3] ]
            ans = check(diag)
            if ans == "":
                diag = [t[3][0], t[2][1], t[1][2], t[0][3]]
                ans = check(diag)
                
        if ans == "" and ongoing:
            ans = "Game has not completed"
        elif ans == "" and not ongoing:
            ans = "Draw"
        elif ans == "X":
            ans = "X won"
        elif ans == "O":
            ans = "O won"
                       
        print "Case #%d:"%i, ans
                
        
