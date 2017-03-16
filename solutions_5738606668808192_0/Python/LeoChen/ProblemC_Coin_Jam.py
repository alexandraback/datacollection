# -*- coding: utf-8 -*-
"""
Created on Sat Apr  9 10:39:32 2016

@author: chenchen
"""
import math
import sys

class CoinJam():
    def __init__(self,n):
        self.__base = n
        self.__primes = [2,3]
        self.generate_primes(n)

    #return ture if num can be divide by the __primes set      
    def is_composer(self, num):
        for i in self.__primes:
            if num % i == 0:
                return True
        return False
    
    #return the first divider if num is a composer:
    #otherwise return None
    def divider(self, num):
        for i in self.__primes:
            if num % i == 0:
                return i
        return None
    
    #generate  primes bounded less than 10 ** [n+1]/2
    def generate_primes(self, n):
        boundary = 10 ** ((n+1)/2)
        for i in xrange(3,boundary,2):
            if self.is_composer(i):
                continue
            else:
                self.__primes.append(i)
    
    #a generator to generate the coin Jam number
    def coin_jam_generator(self):
        start_num = 2**(self.__base - 1) + 1
        #print bin(start_num)
        for i in xrange(start_num, 2 ** self.__base,2):
            #print bin(i)
            base_numbers = self.cal_base_numbers(int(bin(i)[2:]))
            #print base_numbers
            #print map(self.divider, base_numbers)
            if not all(map(self.is_composer, base_numbers)):
                continue
            else:
                yield bin(i)[2:], map(self.divider, base_numbers)
    
    #calcluate the base numbers if input num:
    #return a list
    def cal_base_numbers(self,num):
        result = []
        for b in xrange(2,11):
            result.append(self.cal_base(b,num))
        return result
    
    #calculate the base number of input num, base of num,
    #return the base 10 form
    def cal_base(self, b, num):
        two_base_form = int(bin(num)[2:])
        result = 0
        loops = 0
        while num > 0:
            remainder = num % 10
            result += b ** loops *remainder
            loops += 1
            num = num/10
        return result
            
    
    
    def getCurrent_primes(self):
        return self.__primes

#gather the set of Coins with the same dividers      
class CoinSet():
    def __init__(self,num, divider_list):
        self.__coins = [num]
        self.__dividers = divider_list
    
    def is_belong(self, divider_list_that):
        return self.__dividers == divider_list_that
        
    def add_num(self,num):
        self.__coins.append(num)
    
    def number_of_coins(self):
        return len(self.__coins)
    
    def get_divider_list(self):
        return self.__dividers
        
    def get_coins(self):
        return self.__coins
    
    
#test set       
#n = 16
#cj = CoinJam(n)
#print len(cj.getCurrent_primes())
#print cj.getCurrent_primes()[0:100]

cases = int(raw_input())

for case in xrange(cases):
#    alien_number, source_language, target_language \
#    = raw_input().split()
    base, output_numbers = map(int,raw_input().split())
    #print base, output_numbers
    coin_jam = CoinJam(8)
    
    coin_set_list = []
    coins_generator = coin_jam.coin_jam_generator()
    for coin, diver_set in coins_generator:
        included = False
        for c in coin_set_list:
            if c.is_belong(diver_set):
                c.add_num(coin)
                included = True
                break
        if included == False:
            new_coin_set = CoinSet(coin, diver_set)
            coin_set_list.append(new_coin_set)
            
    coin_set_sorted = sorted(coin_set_list, key = \
    lambda c: c.number_of_coins(),reverse = True)
    
    print("Case #" + str(case+1) +":")
    
    #for case len = 16:
    for coin_set in coin_set_sorted:
        coins = coin_set.get_coins()
        for i in xrange(coin_set.number_of_coins()):
            for j in xrange(i, coin_set.number_of_coins()):
                print coins[i]+coins[j], 
                for div in coin_set.get_divider_list():
                    print div,
                print
                output_numbers -= 1
                if output_numbers == 0:
                    sys.exit()
                    
    #print len(coin_set_list)
            
    
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
    #print("Case #" + str(c+1) +": "+result + "\n")
