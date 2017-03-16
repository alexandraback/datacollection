#!/usr/bin/python

def N(): return tuple(map(int, raw_input().split()))

T = N()[0]
for t in range(1, T + 1):
    smax, P = raw_input().split()
    smax = int(smax)
    friends = 0
    peopleClapping = 0
    for shyness, people in enumerate(P): 
        if peopleClapping < shyness:
            newFriends = shyness - peopleClapping
            friends += newFriends
            peopleClapping += newFriends
        peopleClapping += int(people)

    print "Case #%d: %s" % (t, friends)

