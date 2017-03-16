import sys

def war_optimal(Naomi,Ken):
    Na=0
    Ke=0
    Ken.sort()
    for i in Naomi:
        len_Ken = len(Ken)
        for j in range(len_Ken):
            if i<Ken[j]:
                Ke+=1
                Ken.remove(Ken[j])
                Ken.sort()
                break
        if len_Ken == len(Ken):
                Na+=1
                Ken.remove(Ken[0])
                Ken.sort()

    return Na

def dwar_optimal(Naomi,Ken):
    Na=0
    Ke=0
    Naomi.sort()
    Ken.sort(reverse=True)
    Na_temp = Naomi[:]
    Ke_temp=Ken[:]
    flag=True
    while(Na_temp!=[]):
        len_Na = len(Na_temp)
        for i in range(len_Na):
            if Na_temp[i]>Ke_temp[0]:
                Na+=1
                Na_temp.remove(Na_temp[i])
                Ke_temp.remove(Ke_temp[0])
                break
        if len_Na == len(Na_temp):
                Ke+=1
                Na_temp.remove(Na_temp[0])
                Ke_temp.remove(Ke_temp[0])

    return Na



numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
    N = int(sys.stdin.readline().strip())
    Naomi = [float(i) for i in sys.stdin.readline().strip().split()]
    Ken = [float(i) for i in sys.stdin.readline().strip().split()]
    print 'Case #'+repr(casenum)+": "+str(dwar_optimal(Naomi,Ken)) + " " +str(war_optimal(Naomi,Ken))


