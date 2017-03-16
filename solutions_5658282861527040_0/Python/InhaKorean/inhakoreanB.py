f_test = ['test.in', 'test.out']
f_small = ['B-small-attempt0.in', 'small.out']
f_large = ['B-large.in', 'large.out']
f_practice_small = ['B-small-practice.in', 'practice_small.out']
f_practice_large = ['B-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
FILE_NAME = f_small
#FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')

def case_result(case) :
    A, B, K = [int (i) for i in f.readline().split(' ')]

    case = []
    for i in range(A) :
        for j in range(B) :
            case.append(i&j)
    res = 0
    for i in case :
        if i < K : res += 1
    return str(res)

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
