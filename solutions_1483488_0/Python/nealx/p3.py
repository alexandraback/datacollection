'''
Created on 2012-4-13

@author: nealxyc
'''
import string
import sys
import math
def solve(input):
    nums = input.split(' ')
    a = int(nums[0])
    b = int(nums[1])
    count = 0
    for n in range(a, b + 1):
        s = str(n)
        length = len(s)
        mset = set()
        for i in range(1, len(s)):
            mstr = rotate(s, i)
            m = int(mstr)
            mstr = str(m)
            if m > n and m <= b and len(mstr) == length and mstr not in mset: 
                count += 1
                mset.add(mstr)
    
    return count

def rotate(s, num):
    if len(s) > num:
        return s[-1 - num + 1:] + s[0:len(s) - num]
    return s

if __name__ == '__main__':

    filename = sys.argv[1]
    try:
        with open(filename) as file:
                num = int(file.readline())
                for i in range(1, num +1):
                    print "Case #" + str(i) +': '+ str(solve(file.readline().strip()))
    except IOError:
        pass