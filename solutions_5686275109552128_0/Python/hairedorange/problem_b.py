#-----------------------------------------------------------------------------
#
# 1. If opt solution include n special minutes, they are first n minutes
#
# 2. In a special minute, the one with max num of pancakes share his plate
#
# 3. The max steps we should take (without a "deep look") is the max num panc-
#    akes one has.
#
# 4. The key part of my solution is hard to interperate clearly, so ... :)
#
#-----------------------------------------------------------------------------

import sys

"""
def minstep(plates):
    plates = sorted(plates, reverse = True)
    counter = 0
    if (plates[0] <= 3 ):
        return plates[0]
    threshhold = plates[0] - plates[0] / 2
    for plate in plates[1:]:
        if plate > threshhold:
            counter += 1
        else:
            break
    if counter >= plates[0] / 2 - 1:
        return plates[0]
    plates.append(threshhold)
    plates.append(plates[0] - threshhold)
    del plates[0]
    return minstep(plates) + 1
"""
def minstep(l):
    plates = sorted(l, reverse=True)
    if plates[0] <= 3:
        return plates[0]
    minvalue = plates[0]
    for i in range(2, plates[0] / 2 + 1):
        newplates = plates[1:]
        newplates.append(i)
        newplates.append(plates[0]-i)
        minvalue = min(minvalue, minstep(newplates)+1)
    return minvalue
    

testcasenum = int(sys.stdin.readline())

testcases = []

for i in range(testcasenum):
    dinernum = int(sys.stdin.readline())
    plates = []
    line = sys.stdin.readline().split()
    for j in line:
        plates.append(int(j)) 
    testcases.append((dinernum, plates))

caseno = 1

for testcase in testcases:
    print "Case #"+str(caseno)+":", minstep(testcase[1])
    caseno += 1


