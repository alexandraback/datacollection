import itertools
import sys

def solveCase(f):
    l = map(int, f.readline().split())
    nums = l[1:]
    nums.sort()
    invNums = list(reversed(nums))
    for i in xrange(1, len(nums) + 1):
        for s1 in itertools.combinations(invNums, i):
            sum1 = sum(s1)
            for j in xrange(1, 1 + len(nums)):
                for s2 in itertools.combinations(nums, j):
                    #print s1, s2
                    sum2 = sum(s2)
                    if sum2 == sum1:
                        tempList = list(s1)
                        tempList.sort()
                        if tuple(tempList) == s2:
                            continue
                        ## print s1, s2
                        else:
                            return "\n".join([printset(s1), printset(s2)])
                    elif sum2 > sum1:
                        break
    return "Impossible"
    

def printset(s):
    s = list(s)
    s.sort()
    return " ".join(map(str, s))

def main(fName):
    f = open(fName, "r")
    cases = int(f.readline())
    for i in xrange(cases):
        print "Case #%d:\n%s" % (i + 1, solveCase(f))
    f.close()

main(sys.argv[1])
