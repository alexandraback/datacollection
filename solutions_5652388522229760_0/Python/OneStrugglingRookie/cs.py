import os


os.remove('sub.out')

f = open('A-small-attempt6.in', 'r')

output = open('sub.out','a')
Data = f.read()

Data = Data.split('\n')
#Data = [int(x) for x in Data[:-1]]
T = int(Data[0])
Nlist = Data[1:]


for t in xrange(T):
    N = int(Nlist[t])
    count = 1
    Cand = ['0','1','2','3','4','5','6','7','8','9']
    CandDict = list(Cand)
    Num = N
    flag = False
    NumStr = str(Num)
    for temp in CandDict:
        if temp in NumStr:
            Cand.remove(temp)
    CandDict = list(Cand)
    while count < 10000:
        if len(Cand) == 0:
            flag = True
            break
        count += 1
        Num += N
        NumStr = str(Num)
        for temp in CandDict:
            if temp in NumStr:
                Cand.remove(temp)
        CandDict = list(Cand)
    if flag:
        output.write('Case #'+ str(t+1) + ': '+ NumStr+'\n' )
    else:
        output.write('Case #'+ str(t+1) + ': ' + 'INSOMNIA\n')

output.close()
