#GCJ qualification round templates

##f =open('test.txt','r')
##fout = open('test_result.txt','w')

f =open('A-small-attempt0.in','r')
fout = open('small_result.txt','w')

##f =open('A-large-practice.in','r')
##fout = open('large_result.txt','w')

casenum = int(f.readline().split('\n')[0])
for case in range(casenum):
    lst = f.readline().split('\n')[0].split(' ')
    maxS = int(lst[0])
    shy_str = lst[1]
    #print(type(shy_lst))
    shy_lst = []
    cnt = 0
    
    for char in shy_str:
        shy_lst.append(int(char))

    summ = shy_lst[0]
    for i in range(1,maxS+1):
        if shy_lst[i] != 0:
            if summ < i:
                cnt += i- summ
                summ = summ + cnt + shy_lst[i]
            else:
                summ = summ + shy_lst[i]
    fout.write('Case #'+str(case+1)+': '+str(cnt))
    fout.write('\n')

f.close()
fout.close()
