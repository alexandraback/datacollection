import sys
#import pprint
def work(n,m,data):
    rowmax = [-1]*n
    colmax = [-1]*m
    for i in range(n):
        for j in range(m):
            d = data[i][j]
            if d > rowmax[i]:
                rowmax[i] = d
            if d > colmax[j]:
                colmax[j] = d
    for i in range(n):
        for j in range(m):
            d = data[i][j]
            if not d == rowmax[i] and not d == colmax[j]:
                return "NO"
    return "YES"

if __name__=='__main__':
    fin = open('B-large.in')
    #fin = sys.stdin
    fout = open('b.out','wt')
    line = fin.readline()
    t = int(line)
    for i in range(t):
        (n,m) = fin.readline().strip().split()
        m = int(m)
        n = int(n)
        lines = []
        for j in range(n):
            line = fin.readline().strip().split()
            val = [int(data) for data in line]
            lines.append(val)
        fout.write('Case #%d: %s\n' %(i+1,work(n,m,lines)))
    fout.close()
