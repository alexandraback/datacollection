
from itertools import permutations
from collections import defaultdict
import fileinput







def run(data):
    firstSet = defaultdict(int)
    secondSet = defaultdict(int)

    for first, second in data:
        firstSet[first] += 1
        secondSet[second] += 1

    nowList = []
    remainList = []

    used = [set(), set()]
    
    ans = 0
    for first, second in data:
        if firstSet[first] == 1 or secondSet[second] == 1:
            nowList.append((first, second))
            used[0].add(first)
            used[1].add(second)
        else:
            remainList.append((first, second))



    new_remainList = []
    for first, second in remainList:
        if first in used[0] and second in used[1]:
            ans += 1
        else:
            new_remainList.append((first, second))

    remainList = new_remainList


    while len(remainList) > 0:
        
        idx = 0
        for _idx, (first, second) in enumerate(remainList):
            if first not in used[0] and second not in used[1]:
                idx = _idx

        first, second = remainList[idx]
        remainList = remainList[0:idx] + remainList[idx + 1:]
        


        used[0].add(first)
        used[1].add(second)
        new_remainList = []
        for first, second in remainList:
            if first in used[0] and second in used[1]:
                ans += 1
            else:
                new_remainList.append((first, second))

        remainList = new_remainList



    return ans
        



f = fileinput.input()
T = int(f.next())

for ca in range(T):
    N = int(f.next())
    d = []
    for j in range(N):
        first, second = (f.next()).strip().split()
        d.append((first, second))
    
    ans = run(d)

    print "Case #%s: %s" % (ca + 1, ans)
