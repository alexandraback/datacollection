import sys
import math
#import pprint
def palindrome(i):
    si = str(i)
    ls = list(si)
    ls.reverse()
    sr = ''.join(ls)
    return si == sr

def work(a,b):
    start = int(math.ceil(math.sqrt(a)))
    end = int(math.floor(math.sqrt(b)))
    for i in range(start,end+1):
        if palindrome(i) and palindrome(i*i):
              print '%d,'%(i*i),

if __name__=='__main__':
    a = 1e13
    b = 1e14 - 1
    work(a,b)
