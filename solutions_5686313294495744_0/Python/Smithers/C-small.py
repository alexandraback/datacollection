#!/usr/bin/env python3

# Google Code Jam Round 1B 2016
# Problem C. Technobabble
# Solution in Python
# By Smithers

for x in range(1, int(input()) + 1):
    n = int(input())
    
    firstmap = {}
    secondmap = {}
    
    topicgrid = []
    
    for i in range(n):
        topic = input().split()
        if topic[0] not in firstmap:
            firstmap[topic[0]] = len(firstmap)
        if topic[1] not in secondmap:
            secondmap[topic[1]] = len(secondmap)
        topicgrid.append((firstmap[topic[0]], secondmap[topic[1]]))
    
    y = 0
    for i in range(2 ** n):
        seenfirst = [False] * len(firstmap)
        seensecond = [False] * len(secondmap)
        cfake = 0
        for j, topic in enumerate(topicgrid):
            if i & 2 ** j:
                cfake += 1
            else:
                seenfirst[topic[0]] = True
                seensecond[topic[1]] = True
        if all(seenfirst) and all(seensecond) and cfake > y:
            y = cfake
    
    print('Case #' + str(x) + ':', y)
