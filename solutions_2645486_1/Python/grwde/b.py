import sys

def value(initial,final, cap, regain, index0,indexk):
    if index0>=indexk:
        return 0
    maxindex=index0
    for index in range(index0,indexk):
        if n[index]>n[maxindex]:
            maxindex=index
    availEnergy=min(cap,
                    initial+ regain*(maxindex-index0))
    reserve=max(0,(final-regain*(indexk-maxindex)))
    spendEnergy=availEnergy-reserve
    return (spendEnergy*n[maxindex]+
            value(initial,availEnergy,cap,regain,index0,maxindex)+
            value(regain+reserve,final,cap,regain,maxindex+1,indexk))

T=int(raw_input())
for test in range(1,T+1):
    (cap,regain,maxn)=map(int, (raw_input()).split())
    n=map(int,(raw_input()).split())
    print "Case #{0}: {1}".format(test,value(cap,0,cap,regain,0,maxn))
