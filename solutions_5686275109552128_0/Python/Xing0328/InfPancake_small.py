#Infinate Pancakes

##f =open('test.txt','r')
##fout = open('test_result.txt','w')

f =open('B-small-attempt1.in','r')
fout = open('small_result.txt','w')

##f =open('A-large-practice.in','r')
##fout = open('large_result.txt','w')

casenum = int(f.readline().split('\n')[0])
for case in range(casenum):
    d = int(f.readline().split('\n')[0])
    cake_char = f.readline().split('\n')[0].split(' ')
    cake_num = []
    total = []
    for char in cake_char:
        cake_num.append(int(char)) # num of cakes in each plate
    for n in range(1,10):
        cnt = 0
        for num in cake_num:
            if num % n == 0:
                cnt += num/n -1
            else:
                cnt += num//n
        tol = int(cnt) +n
        total.append(tol)
    min_t = min(total)
    fout.write('Case #'+str(case+1)+': '+str(min_t)+'\n')
                   
f.close()
fout.close()
