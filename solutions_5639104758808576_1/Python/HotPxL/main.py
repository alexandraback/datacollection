#!/usr/bin/env python3.4
import sys

def getSingleDigit(s, i):
    return ord(s[i]) - ord('0')

if __name__ == '__main__':
    testCaseCount = int(sys.stdin.readline())
    for testCase in range(testCaseCount):
        [shyMax, shyList] = sys.stdin.readline().split()
        shyMax = int(shyMax)
        audienceCount = 0
        friends = 0
        for shy in range(shyMax + 1):
            aud = getSingleDigit(shyList, shy)
            if aud != 0:
                if audienceCount < shy:
                    friends += shy - audienceCount
                    audienceCount = shy
                audienceCount += aud
        print('Case #%d: %d' % (testCase + 1, friends))

