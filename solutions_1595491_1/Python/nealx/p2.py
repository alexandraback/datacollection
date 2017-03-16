'''
Created on 2012-4-13

@author: nealxyc
'''
import string
import sys

def solve(input):
    nums = input.split(' ')
    n = int(nums[0])
    surprising = int(nums[1])
    p = int(nums[2])
    scores = [int(nums[i]) for i in range(3, 3 + n)]
    
    left = [ item for item in scores if item < (3*p -2)]
    left = sorted(left, reverse=True)
    
    count = len(scores) - len(left)
    if p > 1:
        for i in range(0, min(surprising, len(left))):
            if left[i] >= 3 * p -4:
                count += 1
    
    return count

if __name__ == '__main__':

    filename = sys.argv[1]
    try:
        with open(filename) as file:
                num = int(file.readline())
                for i in range(1, num +1):
                    print "Case #" + str(i) +': '+ str(solve(file.readline().strip()))
    except IOError:
        pass