#!/usr/bin/env python


inFile = open('in.txt', 'r')
outFile = open('out.txt' ,'w')
t = int(inFile.readline())

for case in range(1,t+1,1):
    

    def getlist(num, temp):
        if len(temp[num]) == 0:
            return [num]
        alllist = []
        lengthlist = []
        for x in temp[num]:
            cur = [num]
            cur += getlist(x,temp)
            lengthlist.append(len(cur))
            alllist.append(cur)
        maxlen = max(lengthlist)
        i = lengthlist.index(maxlen)
        return alllist[i]

            
    def getstudents(pair, temp):
        l1 = getlist(pair[0], temp)
        l2 = getlist(pair[1], temp)
        l = l1+l2
        return l

    
    n = int(inFile.readline())
    liking = {}
    for i in range(1,n+1,1):
        liking[i] = []
    like = map(int, inFile.readline().split(' '))
    pairs = []
    for i in range(n):
        m = like[i]
        liking[m].append(i+1)
        if m in liking[i+1]:
            pairs.append((i+1,m))
    table = []
    start = liking.keys()
    for pair in pairs:
        temp = liking.copy()
        a,b = pair
        start.remove(a)
        start.remove(b)
        temp[a].remove(b)
        temp[b].remove(a)
        l = getstudents(pair, temp)
        table.append(l)
    cur = 0
    for i in range(n):
        l = []
        if i+1 not in start:
            continue
        x = i
        l.append(x+1)
        while like[x] not in l:
            x = like[x] - 1
            l.append(x+1)
        for i in l:
            try:
                start.remove(i)
            except ValueError:
                pass
        m = like[x]
        i = l.index(m)
        length = len(l) - i
        if length > cur:
            cur = length

    pairlen = 0
    for l in table:
        pairlen += len(l)
    if cur > pairlen:
        outFile.write('Case #{}: {}\n'.format(case,cur))
    else:
        outFile.write('Case #{}: {}\n'.format(case, pairlen))
    
