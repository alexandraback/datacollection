f_test = ['test.in', 'test.out']
f_small = ['A-small-attempt1.in', 'small.out']
f_large = ['A-large.in', 'large.out']
f_practice_small = ['A-small-practice.in', 'practice_small.out']
f_practice_large = ['A-large-practice.in', 'practice_large.out']

#FILE_NAME = f_test
#FILE_NAME = f_small
FILE_NAME = f_large
#FILE_NAME = f_practice_small
#FILE_NAME = f_practice_large

f = open(FILE_NAME[0], 'r')
o = open(FILE_NAME[1], 'w')
def case_result(case) :
    R, C, W = map(int,f.readline().split())
    ans = R*(C//W)+(W-1)
    if C % W > 0 :
        ans += 1
    return str(ans)
    
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
