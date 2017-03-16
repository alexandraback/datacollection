from __future__ import division;
from bisect import *;
from fractions import Fraction;
import sys;
import math;
import io;

INF = 987654321987654321987654321;

def readint(delimiter=' ') :
	return map(int, raw_input().split(delimiter));

def readstr() :
	return raw_input().split();

def readfloat() :
	return map(float, raw_input().split());

def index(a, x):
    'Locate the leftmost value exactly equal to x'
    i = bisect_left(a, x)
    if i != len(a) and a[i] == x:
        return i
    raise ValueError

def find_lt(a, x):
    'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

def find_ge(a, x):
    'Find leftmost item greater than or equal to x'
    i = bisect_left(a, x)
    if i != len(a):
        return a[i]
    raise ValueError


def bin_search(a, x, left, right) :

    while left<=right :
        mid = (left + right)//2;
        
        if a[mid] == x :
            return mid;
        elif a[mid] < x :
            left = mid + 1; 
        elif a[mid] > x :
            right = mid - 1;
                       
        pass
    
    return -1;
    pass

if __name__ == '__main__':
	
    def is_palin(strin) :
        left = 0;
        right = len(strin) - 1;
        while (left < right) :
            if strin[left] != strin[right] :
                return False;
            else :
                left += 1;
                right -= 1;

        return True;
    arr = [];
    sol = [1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004];
    '''
    for ii in xrange(1, 10**7+1) :
        now = ii**2;
        if is_palin(str(ii)) and is_palin(str(now)) :
            arr.append(now);

    print '[%s]'%(','.join(map(str,arr)));
    '''
    tc = input();
    for tt in xrange(tc) :
        a, b = readint();
        total = 0;
        for item in sol :
            if a <= item <= b :
                total += 1;
                pass
            pass
        print 'Case #%d: %d' %(tt+1, total);
        pass




    pass