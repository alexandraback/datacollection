'''
Created on 2012/04/14

@author: teraotsuyoshi
'''

        
if __name__ == '__main__':
    lines = open("B-small-attempt0.in").readlines()
    T = int(lines[0])
    ln = 1
    for i in range(1, T+1):
        (N,M) = lines[ln].split()
        M = int(M)
        N = int(N)
        t = []
        ln = ln + 1
        for j in range(N):
            cols = list()
            for x in lines[ln].split():
                cols.append(int(x))
            t.append(cols)
            ln = ln + 1
            
        #t[row][col]

        max_row = list()
        for r in range(N):
            max_row.append(max(t[r]))
        
        max_col = list()
        for c in range(M):
            m = 0
            for r in range(N):
                if m < t[r][c]:
                    m = t[r][c]
            max_col.append(m)
            
        ans = "YES"
        for r in range(N):
            for c in range(M):
                if t[r][c] < max_row[r] and t[r][c] < max_col[c]:
                    ans = "NO" 
            
        print "Case #%d:"%i, ans
                
        
