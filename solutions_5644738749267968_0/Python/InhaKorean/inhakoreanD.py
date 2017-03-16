f_small = ['D-small-attempt0.in', 'small.out']
f_large = ['D-large.in', 'large.out']

FILE_NAME = f_small
#FILE_NAME = f_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def case_result(case) :
    res_a = 0
    res_b = 0
    
    n     = int(f.readline())
    naomi = [float (i) for i in f.readline().split(' ')]
    ken   = [float (i) for i in f.readline().split(' ')]
    
    naomi.sort()
    ken.sort()

    naomi_a = naomi[:]
    ken_a   = ken[:]
    naomi_b = naomi[:]
    ken_b   = ken[:]

    for i in range(n) :
        if naomi_a[0] < ken_a[0] :
            naomi_a.pop(0)
            ken_a.pop()
        else :
            naomi_a.pop(0)
            ken_a.pop(0)
            res_a = res_a+1

    for i in range(n) :
        if naomi_b[-1] > ken_b[-1] :
            naomi_b.pop(-1)
            ken_b.pop(0)
            res_b = res_b+1
        else :
            for j in range(len(ken_b)) :
                if naomi_b[-1] < ken_b[j] :
                    ken_b.pop(j)
                    break;
            naomi_b.pop(-1)
        
    return str(res_a) +" "+str(res_b)
            
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
