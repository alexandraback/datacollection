# Encoding: utf-8
'''
Created on 13.04.2013

@author: Los

@version: 0.0.1
'''
import sys

def main(argv=None):
    if argv==None : argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')
    
    T=int(input())
    for i in range(1, T+1):
        l=input().strip().split()
        N=int(l[0])
        M=int(l[1])
        rows=list()
        r=list()
        for n in range(N):
            l=input().strip().split()
            rows.append(list())
            r.append(list())
            for m in l :
                rows[n].append(int(m))
                r[n].append(0)
        #rows
        for n in range(N):
            mmax=max(rows[n])
            for m in range(M):
                if rows[n][m]==mmax :
                    r[n][m]=1
        #cols
        for m in range(M):
            mmax=0
            for n in range(N):
                mmax=max(mmax,rows[n][m])
            for n in range(N):
                if rows[n][m]==mmax :
                    r[n][m]=1
        result=True
        for n in range(N):
            for m in range(M):
                if r[n][m]==0 :
                    result=False
                    break
            if not result :
                break
        if result :
            print('Case #{}: YES'.format(i))
        else:
            print('Case #{}: NO'.format(i))
            
        
        

if __name__ == '__main__':
    main()
