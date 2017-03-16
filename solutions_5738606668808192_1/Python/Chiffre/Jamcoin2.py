t=int(raw_input())

def main(n,j):
    l=[]
    for k in range(0,(n-2)/2,1):
        for i in range(n-1-2*k-2):
            for q in range(k+1):
                l.append('0'*(i)+'1'+'0'*(q)+'1'+'1'+'0'*(2*k-q)+'1'+'0'*(n-2-i-k*2-2))

    return l[:j]

for i in range(t):
    n,j = map(int, raw_input().strip().split())
    print 'Case #'+str(i+1)+':'
    for i in main(n-2,j):print '1'+i+'1 3 4 5 6 7 8 9 10 11'
