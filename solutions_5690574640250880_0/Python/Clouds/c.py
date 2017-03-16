#!/usr/bin/python

f=open('C-small-attempt3.in','r')

n=int(f.readline())
for t in range(1,n+1):
    r,c,m=[int(x) for x in f.readline().split()]
    print('Case #%d:'%t)
    #print(r,c,m)
    s=r*c-m
    if s<=0:
        print('Impossible')
    elif r==1:
        print('c'+'.'*(s-1)+'*'*m)
    elif r==2:
        if s==1:
            print('c'+'*'*(c-1))
            print('*'*c)
        elif s==2 and c==1:
            print('c')
            print('.')
        elif s>2 and s%2==0:
            ss,mm=int(s/2),int(m/2)
            print('c'+'.'*(ss-1)+'*'*mm)
            print('.'*ss+'*'*mm)
        else:
            print('Impossible')
    elif c==1:
        print('c\n'+'.\n'*(s-1)+'*\n'*m,end='')
    elif c==2:
        if s==1:
            print('c*\n'+'**\n'*(r-1),end='')
        elif s>2 and s%2==0:
            ss,mm=int(s/2),int(m/2)
            print('c.\n'+'..\n'*(ss-1)+'**\n'*mm,end='')
        else:
            print('Impossible')
    else:
        if s==1:
            print('c'+'*'*(c-1))
            print(('*'*c+'\n')*(r-1),end='')
        elif s==4 or s==6:
            ss=int(s/2)
            print('c'+'.'*(ss-1)+'*'*(c-ss))
            print('.'*ss+'*'*(c-ss))
            print(('*'*c+'\n')*(r-2),end='')
        elif s>=8 and s<=2*c:
            ss=int((s-2)/2)
            print('c'+'.'*(ss-1)+'*'*(c-ss))
            print('.'*ss+'*'*(c-ss))
            print('..'+(s%2==1 and '.' or '*')+'*'*(c-3))
            print(('*'*c+'\n')*(r-3),end='')
        elif s>2*c:
            rr=int(s/c)
            if s%c==0:
                print('c'+'.'*(c-1))
                print(('.'*c+'\n')*(rr-1),end='')
                print(('*'*c+'\n')*(r-rr),end='')
            elif s%c==1:
                if rr>2:
                    print('c'+'.'*(c-1))
                    print(('.'*c+'\n')*(rr-2),end='')
                    print('.'*(c-1)+'*')
                    print('..'+'*'*(c-2))
                    print(('*'*c+'\n')*(r-rr-1),end='')
                elif rr==2 and c>3:
                    print('c'+'.'*(c-2)+'*')
                    print('.'*(c-1)+'*')
                    print('...'+'*'*(c-3))
                    print(('*'*c+'\n')*(r-rr-1),end='')
                else:
                    print('Impossible')
            else:
                print('c'+'.'*(c-1))
                print(('.'*c+'\n')*(rr-1),end='')
                print('.'*(s%c)+'*'*(c-s%c))
                print(('*'*c+'\n')*(r-rr-1),end='')
        else:
            print('Impossible')

