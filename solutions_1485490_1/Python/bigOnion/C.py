directory = 'C:/users/hai/my projects/google code jam/2012/1C/C/'

q1 = []
q2 = []
memo = {}

def solve (f_in, f_out):
    global q1
    global q2
    global memo
    T = int(f_in.readline())
    for testcase in range(1,T+1):
        N,M = [int(x) for x in f_in.readline().split()]
        l1 = [int(x) for x in f_in.readline().split()]
        l2 = [int(x) for x in f_in.readline().split()]
        assert len(l1) == N*2
        assert len(l2) == M*2
        q1 = []
        q2 = []
        memo = {}
        for i in range(N):
            q1.append((l1[i*2],l1[i*2+1]))
        for i in range(M):
            q2.append((l2[i*2],l2[i*2+1]))

        res = memo_search (q1[0][0],q2[0][0],0,0)

        f_out.write('Case #' + str(testcase) + ': ' + str(res) + '\n')


def memo_search (remain_q1, remain_q2, loc_q1, loc_q2):
    global q1
    global q2
    global memo
    
    if (remain_q1, remain_q2, loc_q1, loc_q2) in memo:
        return memo[(remain_q1, remain_q2, loc_q1, loc_q2)]
    
    if loc_q1 >= len(q1):
        return 0
    if loc_q2 >= len(q2):
        return 0
    
    if remain_q1 == 0:
        if loc_q1 == len(q1)-1:
            memo[(remain_q1, remain_q2, loc_q1, loc_q2)] = 0
            return 0
        else:
            result = memo_search(q1[loc_q1+1][0], remain_q2,loc_q1+1,loc_q2)
            memo[(remain_q1, remain_q2, loc_q1, loc_q2)] = result
            return result

    if remain_q2 == 0:
        if loc_q2 == len(q2)-1:
            memo[(remain_q1, remain_q2, loc_q1, loc_q2)] = 0
            return 0
        else:
            result = memo_search(remain_q1, q2[loc_q2+1][0],loc_q1,loc_q2+1)
            memo[(remain_q1, remain_q2, loc_q1, loc_q2)] = result
            return result

    
    item1 = q1[loc_q1][1]
    item2 = q2[loc_q2][1]
    if item1 == item2:
        addition = min (remain_q1, remain_q2)
        result = addition + memo_search(remain_q1-addition, remain_q2-addition,loc_q1,loc_q2)
        memo[(remain_q1, remain_q2, loc_q1, loc_q2)] = result
        return result

    tmp1 = 0
    tmp2 = 0
    if loc_q1 < len(q1)-1:
        # throw from queue1
        tmp1 = memo_search (q1[loc_q1+1][0], remain_q2,loc_q1+1,loc_q2)
        
    if loc_q2 < len(q2)-1:
        # throw from queue1
        tmp2 = memo_search (remain_q1, q2[loc_q2+1][0],loc_q1,loc_q2+1)

    result = max(tmp1,tmp2)
    memo[(remain_q1, remain_q2, loc_q1, loc_q2)] = result
    return result







def main_run():
    import os
    import time
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_ctime, x) for x in filenames]
    chosen_filename =  sorted(l1)[-1][1][:-3]

    print ('Directory : ', directory)
    print ('Chosen Filename : ',chosen_filename)
    print()
    print ('Start : ', time.ctime())
    print()
    
    f_in = open(directory+chosen_filename+'.in')
    f_out = open(directory+chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()

    print ()
    print ('End : ', time.ctime())


main_run()


