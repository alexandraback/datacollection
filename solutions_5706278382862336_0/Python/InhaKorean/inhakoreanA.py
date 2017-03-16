f_test = ['test.in', 'test.out']
f_small = ['A-small-attempt1.in', 'small.out']
f_large = ['A-large.in', 'large.out']
f_practice_small = ['A-small-practice.in', 'practice_small.out']
f_practice_large = ['A-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def case_result(case) :
    P, Q = [int(i) for i in f.readline().split('/')]
    res = 0

    t = Q
    for i in range(40) :
        if t == 1 : break;
        if t % 2 == 1 : return "impossible" 
        t = t/2
        
    p = float(P/Q)
    for i in range(40) :
        if p >= 1 : return str(res)
        p = p*2
        res += 1

    if p == 1 : return str(res)
    else : return "impossible"
        

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
