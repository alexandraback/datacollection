#!/usr/bin/env python

import fileinput, collections, sys, operator, itertools

def autodict():
    return collections.defaultdict(autodict)

def input():
    it = iter(itertools.imap(str.rstrip, fileinput.input()))
    it.next()
    while True:
        yield map(int, it.next().rstrip().split())[1:]

def main():
    for casenum, nums in enumerate(input()):
        allSums = {}
        def doit(nums, i=0, bitmap=0, sum=0):
            if i == len(nums):
                if sum not in allSums:
                    allSums[sum] = []
                if sum != 0:
                    allSums[sum].append(bitmap)
            else:
                doit(nums, i+1, bitmap, sum)
                doit(nums, i+1, bitmap + (1 << i), sum + nums[i])

        doit(nums)

        def convertToList(bitmap):
            res = []
            for i in range(len(nums)):
                if bitmap & 1:
                    res.append(nums[i])
                bitmap >>= 1
            return res

        done = False
        for sum in allSums:
            bitmaps = allSums[sum]
            for i in range(len(bitmaps)):
                for j in range(i+1, len(bitmaps)):
                    if bitmaps[i] & bitmaps[j] == 0:
                        bitmap1 = bitmaps[i]
                        bitmap2 = bitmaps[j]
                        done = True
                    if done: break
                if done: break
            if done: break
        if done:
            list1 = convertToList(bitmaps[i])
            list2 = convertToList(bitmaps[j])
            print "Case #%d:\n%s\n%s" % (casenum+1, ' '.join(map(str,list1)), ' '.join(map(str,list2)))
        else:
            print "Case #%d:\nImpossible" % (casenum+1)

main()
