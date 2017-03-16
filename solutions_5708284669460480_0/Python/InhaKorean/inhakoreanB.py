f_test = ['test.in', 'test.out']
f_small = ['B-small-attempt3.in', 'small.out']
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

import itertools

LL = []
def s(Key, S, k) :
    global LL
    if len(k) == S :
        LL.append("".join(k))
        return None

    for i in Key :
        k.append(i)
        s(Key, S, k)
        k.pop(-1)
    return None

def count(i, Target) :
    ret = 0
    for x in range(len(i)) :
        if i[x:x+len(Target)] == Target : ret += 1
    return ret

def case_result(case) :
    global LL
    K, L, S= map(int, f.readline().split())
    LL = []
    Key = f.readline()
    Target = f.readline()
    
    if Key[-1] < 'A' or Key[-1] > 'Z' :
        Key = Key[:-1]
    if Target[-1] < 'A' or Target[-1] > 'Z' :
        Target = Target[:-1]

    max_val = 0
    s(Key, S, [])
    cnt = len(LL)
    t_cnt = 0
    for i in LL :
        c = count(i, Target)
        max_val = max(max_val, c)
        t_cnt += c
    if t_cnt == 0 : return '0.0'
    ans = ((cnt*max_val) - t_cnt)/cnt
    ans = round(ans, 7)
    return str(ans)
     
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
