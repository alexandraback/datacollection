import sys
import itertools
import operator

T=int(raw_input())
print "Case #1:"

(R,N,M,K) = map(int, (raw_input()).split())

possible = list(itertools.combinations_with_replacement(range(2,M+1),N))
#all N combinations of digits <=M

total=[0]*1000000
mult=[]
for (index, combination) in enumerate(possible):
    distribution={}
    for size in range(1,N+1):
        for subset in itertools.combinations(combination,size):
            p=reduce(operator.mul,subset,1)
            total[p]=total[p]+1
            if p in distribution:
                distribution[p]=distribution[p]+1
            else:
                distribution[p]=1        
            mult.append(distribution)

def chance(combination, product):
    if product in mult[combination]:
        return float(100*mult[combination][product])/total[product]
    else:
        return 0
        
for r in range(0,R):
    products=map(int,(raw_input()).split())
    chances=[sum(map(lambda prod:chance(index,prod), products)) for index in range(0, len(possible))]
    maxcombination=0
    for i in range(0,len(possible)):
        if chances[i]>chances[maxcombination]:
            maxcombination=i

    string=""
    for d in possible[maxcombination]:
        string=string+str(d)
    print string
