f_test = ['test.in', 'test.out']
f_small = ['B-small-attempt2.in', 'small.out']
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

def recul(S, st) :
    ch_list = []

    #print(st)
    for i in range(len(st)) :
        if st[i] not in ch_list :
            ch_list.append(st[i])
        else :
            if ch_list[-1] != st[i] :
                return 0

    ch_list2 = ch_list[:-1]
    for i in range(len(S)) :
        for j in range(len(S[i])) :
            if S[i][j] in ch_list2 : return 0

    if len(S) == 0 : return 1
    
    res = 0
    for i in range(len(S)) :
        S2 = S[:]
        res += recul(S2, st + S2.pop(i))

    return res

def case_result(case) :
    N = int(f.readline())
    S = [i for i in f.readline()[:-1].split(' ')]
    for i in range(len(S)) :
        t_s = S[i][0]
        for j in range(1, len(S[i])) :
            if t_s[-1] == S[i][j] : continue
            else : t_s += S[i][j]
        S[i] = t_s
            
    st = ''
    print(case)
    res = recul(S, st)
    return str(res)

    
T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')

f.close()
o.close()
    
    
