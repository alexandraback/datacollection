import numpy as np

def solution(armyLists):
    missingNumbers = []
    for i in range(max(armyLists)+1):
        if sum([int(x==i) for x in armyLists])%2 != 0:
            missingNumbers += [i]
    sortedList = np.sort(missingNumbers)
    output = ''
    for t in sortedList: output += ' ' + str(t)
    return output

for i in range(1,int(input())+1):
    N = int(input())
    armyLists = []
    for j in range(2*N-1):
        armyLists += list(map(int,input().split(' ')))
        #print(armyLists)
    
    print('Case #{}:{}'.format(i,solution(armyLists)))