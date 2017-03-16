f_small = ['B-small-attempt0.in', 'small.out']
f_large = ['B-large.in', 'large.out']

#FILE_NAME = f_small
FILE_NAME = f_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def case_result(case) :
    p = 2.0
    delay = 0.0
    
    C, F, X = [float (i) for i in f.readline().split(' ')]
    while(True) :
        if X/p <= C/p + X/(p+F) :
            return str(delay + X/p)
        else :
            delay = delay + C/p
            p = p + F
            
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
