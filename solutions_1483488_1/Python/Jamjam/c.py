'''
Created on 13 apr. 2012

@author: Peter
'''
import time
from sys import *
import copy     


def get_variations(string):
    variations=[]
    for x in xrange(1, len(string)):
        if string[-x:]+string[:-x] not in variations:
            variations.append(string[-x:]+string[:-x])
    return variations
def solve(numbers):
    match=0
    number1, number2=numbers
    for i in xrange(number1, number2+1):
        varia= get_variations(str(i))     
        for var in varia:
            var=int(var)
            if var >=number1 and var < i:
                match+=1                        
    return match
        
    
cases = int(raw_input())
for case in xrange(1, cases + 1):
    items = map(int, stdin.readline().split())
    start=time.time()
    print "Case #%s: %s" % (case,solve(items))
    #print time.time()-start