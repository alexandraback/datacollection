import math
from collections import Counter
from itertools import product

def occurrences(string, sub):
    count = start = 0
    while True:
        start = string.find(sub, start) + 1
        if start > 0:
            count+=1
        else:
            return count

def solve():
    a=input()
    K=int(a.split()[0])
    L=int(a.split()[1])
    S=int(a.split()[2])
    charK=input()
    target = input()

    countP=Counter()
    for i in product(charK,repeat=S):
        prod="".join(i)
        countP[prod]+=1

    total=0

    max=0
    for i in countP:
        num = occurrences(i,target)
        total += num*countP[i]
        if num > max:
            max=num

    return str(max - total/(K**S))

T=int(input());

for t in range(1,T+1):
    print ("Case #" + str(t) + ": " + solve())