# -*- coding: utf-8 -*-
"""
Created on Sun Nov  8 06:29:02 2015

@author: chenchen
"""

#run: python PromblemA_Counting_Sheep.py file_in > file_out
import sys
f_name = sys.argv[1]
w_name = sys.argv[3]
print sys.argv

#define the solution class
class CountSheep():
    def __init__(self,n):
        self.__start_number = n
        
    #return the output
    def result(self):
        if self.__start_number == 0:
            return "INSOMNIA"
        left_numbers = set(map(str,range(10))) #the 
        loop_number = self.__start_number
        while len(left_numbers) > 0:
            current_numbers = set(str(loop_number))
            left_numbers = left_numbers - current_numbers
            if len(left_numbers) == 0:
                return loop_number
            else:
                loop_number += self.__start_number
            
    
#test case:
#f = open("test.txt")

#input file handle
f = open(f_name)

#output file handel 
w = open(w_name, 'w')

cases = int(f.readline())

for c in xrange(cases):
#    alien_number, source_language, target_language \
#    = f.readline().split()
#    
#    base = len(source_language)
#    temp_result = 0
#    #print source_language
#    for s in alien_number:
#        #print temp_result , s , base, source_language.index(s)
#        temp_result = source_language.index(s) + temp_result * base
#        #print temp_result
#    #translate into target language:
#    result = ""
#    base_target = len(target_language)
#    #print temp_result
#    while(temp_result != 0):
#        remainder = temp_result % base_target
#        result = target_language[remainder] + result
#        temp_result /= base_target
    start_number = int(f.readline())
    cs = CountSheep(int(start_number))
    result = cs.result()
    w.write("Case #" + str(c+1) +": "+str(result) + "\n")

w.flush()
w.close()

f.close()