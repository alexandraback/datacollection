f_test = ['test.in', 'test.out']
f_small = ['A-small-attempt0.in', 'small.out']
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
    N = int(f.readline())
    Q = [1]
    D = [1]
    visited = set()
    while True :
        q = Q.pop(0)
        d = D.pop(0)
        if q in visited : continue
        visited.add(q)
        if q == N : return str(d)
        Q.append(q+1)
        D.append(d+1)
        Q.append(int(str(q)[::-1]))
        D.append(d+1)
    #return str(ans)

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
