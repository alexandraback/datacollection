'''
Created on 2012-4-13

@author: nealxyc
'''
import string
import sys
import math

def solve(ab, ps):
    nums = ab.split(' ')
    a = int(nums[0])
    b = int(nums[1])
    parray = [ float(item) for item in ps.split(' ')]
    keypress = []
    p = 1
    for i in range(0, a):
        p = p * parray[i]
        keyp = p * (a - 1 - i + b - i - 1 + 1) + (1 - p) * (a - 1 - i + b - i - 1 + 1 + b + 1) 
        
        keypress.append( keyp )
    keypress.append(b + 2)
    
    return min(keypress)

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
                    ab = file.readline().strip()
                    ps = file.readline().strip()
                    print "Case #" + str(i) +': %f' % solve(ab, ps)
    except IOError:
        pass