# Encoding: utf-8
'''
Created on 12.04.2014

@author: Los

@version: 0.0.1
'''
import sys
import bisect, collections

def main(argv=None):
    if argv is None:
        argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')
    
    T = int(input())
     
    for i in range(T):
        n=int(input())
        ln=list(map(float, input().split()))
        lk=list(map(float, input().split()))
        ln.sort()
        lk.sort()
        
        
        tk=list(lk)
        ws=0
        for it in ln:
            pos=bisect.bisect_left(tk, it)
            if pos==len(tk):
                tk.pop(0)
                ws+=1
            else:
                tk.pop(pos)
        
        tn=list(ln)
        ds=0
        for it in lk:
            pos=bisect.bisect_left(tn, it)
            if pos==len(tn):
                tn.pop(0)
            else:
                tn.pop(pos)
                ds+=1
        
        print('Case #{0}: {1} {2}'.format(i+1,ds,ws))
        

if __name__ == '__main__':
    main()
