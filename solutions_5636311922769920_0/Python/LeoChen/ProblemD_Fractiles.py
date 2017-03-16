# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 10:39:32 2016

@author: chenchen
"""

#test stdin

cases = int(raw_input())

#w = open(w_name, 'w')

#a problem of calculate K base values, form of [K-1, K-2, ... K -C],....,
#[K-nC - 1,...,2,1,0,0,0]
def select_block(base, begin, steps):
    #print base, begin, steps
    result = 0;
    current_value = begin
    for i in xrange(steps):
        result = result * base + current_value
        if current_value > 0:
            current_value -= 1
    return result+1


for case in xrange(cases):
#    alien_number, source_language, target_language \
#    = raw_input().split()

    K, C, S = map(int, raw_input().split())

    # C*S < K impossible
    if C * S < K:
        print "Case #" + str(case+1) +": "+"IMPOSSIBLE"
    else:
        print "Case #" + str(case+1) +":",
        for i in xrange(S):
            if C * i >= K:
                break
            print select_block(K, K - 1 -i*C, C),
        print

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
