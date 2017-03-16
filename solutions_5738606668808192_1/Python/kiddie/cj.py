import numpy as np
import random
import math
def coinjam():
    f = open('input3','r')
    in_d = f.read()
    in_d = in_d.split()
    N = int(in_d[1])
    J = int(in_d[2])
    J_done = 0
    num_considered = [] 
    print 'Case #1:'
    while(J_done!=J):
        num = gennum(N)
        if num in num_considered:
            continue
        num_considered.append(num_considered)
        flag = True
        vals = np.zeros(9,dtype=int)
        for i in xrange(2,11):
            numr = int(num,i)

            for j in xrange(2,int(math.ceil(numr**0.1))+2):
                if(numr % j == 0):
                    vals[i-2] = j
                    break
            if(j == int(math.ceil(numr**0.1)+1)):
                flag =False
            if(flag == False):
                break
        if(flag == True):
            J_done = J_done+1
            print num,
            for val in vals:
                print val,
            print
def gennum(N):
    num = '1'
    num+=''.join([random.choice(['0','1']) for i in xrange(N-2)])
    num += '1'
    return num

coinjam()

