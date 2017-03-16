import sys
from itertools import *

def setIsValid(trains):
    for ii in range(len(trains)):
        train = trains[ii]
        seen = set([])
        last_let = train[0]
        for let in train:
            if let != last_let and let in seen:
                return False
            seen.add(let)
            last_let = let

        for jj in range(1, len(train) - 1):
            let = train[jj]
            if let != train[0] and let != train[-1]:
                if train[0] == train[-1]: return False
                for kk in range(len(trains)):
                    if kk != ii and let in trains[kk]:
                        return False
    return True



def isValidTest(perm, trains, num_trains):
    string = []
    for ii in range(num_trains):
        string += trains[perm[ii]]
    seen = set({})
    last_let = string[0]
    for let in string:
        if let != last_let and let in seen:
            return False
        seen.add(let)
        last_let = let
    return True

def isValid(perm, trains, num_trains):
    perm, trains, num_trains
    curr_let = trains[perm[0]][0]
    seen = set({})
    for ii in range(num_trains):
        if trains[perm[ii]][0] != curr_let and trains[perm[ii]][0] in seen:
            return False
        curr_let = trains[perm[ii]][0]
        seen.add(curr_let)
        if trains[perm[ii]][-1] != curr_let and trains[perm[ii]][-1] in seen:
            return False
        curr_let = trains[perm[ii]][-1]
        seen.add(curr_let)

    return True

f = open(sys.argv[1])
T = int(f.readline())
for test in range(T):
    num_trains = int(f.readline())
    trains = map(list, f.readline().strip().split())
    total_score = 0
    if setIsValid(trains):
        for perm in permutations(range(len(trains))):
            if isValid(perm, trains, num_trains):
                total_score += 1


    total_score = total_score % 1000000007

    print "Case #%d:" % (test + 1), total_score

