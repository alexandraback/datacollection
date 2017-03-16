import itertools

filein = open('D:\\Users\\john\\My Documents\\Google Code Jam 2014\\lottery_small.txt','r+')
fileout = open('D:\\Users\\john\\My Documents\\Google Code Jam 2014\\lottery_small_answer.txt','w+')

T = int(filein.readline())
for case in range(T):
    [A, B, K] = list(map(int,(filein.readline().split())))
    
    a_values = range(A)
    b_values = range(B)
    
    pairs = list(itertools.product(a_values, b_values))
    and_values = []
    for p in pairs:
        and_values.append(p[0] & p[1])
        
    answer = 0
    for val in and_values:
        if val < K:
            answer += 1
    
    fileout.write('Case #'+str(case+1)+': '+str(answer)+'\n')
    
filein.close()
fileout.close()