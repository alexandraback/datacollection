import math
fin = open('B-large.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    d = int(fin.readline())
    p = [int(i) for i in fin.readline().split()]
    result = sum(p)
    flag = 1
    bound = 2
    while (bound <= max(p) and flag):
        time = 0
        for i in p:
            time += math.ceil(i / bound) - 1
        time += bound
        if time < result:
            result = time
        else:
            flag = 1
        bound += 1
    fout.write('Case #'+str(count)+': '+ str(result) +'\n')
fin.close()
fout.close()
