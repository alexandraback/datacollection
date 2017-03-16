import math
fout=open("jam.out","w")
fout.write("Case #1:\n")
def base2(n,d):
    s=''
    for j in range(d):
        t=d-1-j
        if n>=2**t:
            n-=2**t
            s=s+'1'
        else:
            s=s+'0'
    return s
for dummy in range(50):
    a=base2(dummy,6)
    t='1'+a+'1'+'1'+a+'1'
    fout.write(t+' ')
    for j in range(2,11):
        fout.write(str(j**8+1)+' ')
    fout.write('\n')
fout.close()
    
