import sys,os
import math

def get_int(f):
    return int(f.readline())

def get_line_int(f):
    return map(int,f.readline().split())

def do_all(file_name):
    file_name1 = os.path.splitext(file_name)[0]+'.out'
    with open(file_name) as f1:
        with open(file_name1,'w') as f2:
            calculation(f1,f2)

def sqrt(n):
    S1,S2 = n+1,n
    while S1>S2:
        S1,S2 = S2,(S2+n/S2)/2
    return S1

def calculation(f_in,f_out):
    n = get_int(f_in)
    for case in xrange(1,n+1):
        r,t = get_line_int(f_in)
        S1 = 2*r-1
        val = (-S1+int(sqrt(S1*S1+8*t)))/4
        print >>f_out,'Case #%s:'%case,val

if __name__ == '__main__':
    do_all(sys.argv[1])
