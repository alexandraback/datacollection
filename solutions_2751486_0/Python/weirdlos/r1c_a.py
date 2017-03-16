# Encoding: utf-8
'''
Created on 12.05.2013

@author: Los

@version: 0.0.1
'''
import sys

VOW='aeiou'
CON='bcdfghjklmnpqrstvwxyz'

def main(argv=None):
    if argv==None : argv=sys.argv

    import locale
    locale.setlocale(locale.LC_ALL, '')

    T = int(input())
    for k in range(1, T + 1):
        l=input().strip().split()
        name=l[0]
        n=int(l[1])
        nvalue=0
        name1=''
        for letter in name :
            if letter in VOW :
                name1+='0'
            else :
                name1+='1'
        #print(name1)
        len_name=len(name1)
        substr='1'*n
        if len_name>=n :
            for i in range(0,len_name-n+1):
                for j in range(i+n, len_name+1) :
                    #print(name1[i:j])
                    if name1.find(substr,i,j)>=0 :
                        nvalue+=1
        print('Case #{}: {}'.format(k,nvalue))


if __name__ == '__main__':
    main()