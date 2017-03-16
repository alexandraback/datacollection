# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 10:39:32 2016

@author: chenchen
"""

#test stdin

class RevengePancake():
    def __init__(self, input_cakes):
        self.__cakes = input_cakes
        
    def get_patterns(self):
        return self.__cakes
        
    #return the time to revenge
    def revenge_times(self):
        if len(self.__cakes) <=0 :
            return 0
        else:
            pattern = self.__cakes.split("+")
            l_pattern = len(pattern) - pattern.count("")
            #print pattern, len(pattern), pattern.count(""), l_pattern
            if len(pattern) == 0:
                return 0
            else:
                if self.__cakes.startswith("+"):
                    reminder = 1
                else:
                    reminder = 0
            return l_pattern *2 + reminder - 1
#            result = 0
#        while len(self.__cakes) > 0 :
#            self.__cakes = self.__cakes.rstrip("+")
#            if len(self.__cakes) == 0:
#                return result
#            else:
#                self.revenge_pancake()
#                result += 1
    
    #revenge the cakes
#    def revenge_pancake(self):
#        #step1: revert
#        self.__cakes =self.__cakes[::-1]
#        
#        #step2: reverse +/-
#        self.__cakes = "".join(map(self.reverse, self.__cakes))
#        
#    def reverse(self,c):
#        if c == "+":
#            return "-"
#        if c == "-":
#            return "+"

cases = int(raw_input())
for c in xrange(cases):

#    alien_number, source_language, target_language \
#    = raw_input().split()
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
    cakes = raw_input()
    #print cakes
    rp = RevengePancake(cakes)
    #print rp.get_patterns()

    result = rp.revenge_times()
    #print result
    print("Case #" + str(c+1) +": "+str(result))

#w.flush()
#w.close()