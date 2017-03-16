#import numpy as np

myinf = "sample.txt"
myinf = "A-small-attempt2.in"
#myinf = "B-large-practice.in"

myout = open("output.txt",'wt')
#myout = open("output1.txt",'wt')
#myout = open("output2.txt",'wt')

#import sys
#sys.setrecursionlimit(2000)
def reverse(num):
  return int(str(num)[::-1])

def count(num):
    d = len(str(num))-1
    a=int('1'+'0'*d)
    b=int('2'+'0'*d)
    #print(a,b,num)
    if num<=20:
        y = num
    elif num>=a and num<=b:
        c=(num-a+1)
        #print('c',c)
        y = count(num-c)+c
    else:
        m = int('1'+'0'*((d+1)//2))
        #print('m',num%m)
        y = num%m+count(reverse(num-num%m+1))
    return y
    
myin = open(myinf,'rt').read().split('\n')
num_case = int(myin[0])
print(num_case)
for i in range(num_case):
    '''
    12-19:100
    102-109:1000
    1002-1009:10000
    '''
    shift=i+1
    N = int(myin[shift])
    y = count(N)
    print(i,N,y)
    myout.write("Case #%d: %s\n"%((i+1),y))

myout.close()    
