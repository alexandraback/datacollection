f = open('C-large.in', 'r')
fo = open('out_code3_large.out', 'w')

import math

def convert_base_n(a, n):#input a is list, n is base to be converted to
    number = 0
    index = 1
    length = len(a)
    for i in xrange(length):
        number += a[length - i - 1]*index
        index = index * n
    return number

def find_divisor(a, n, k):#input a is a list, n is the base, and we find proper divisors smaller than k
    length = len(a)
    if length==2:
        return False
    number = convert_base_n(a, n)
    limit = min(k, int(math.floor(number**0.5)) + 1) #the limit that we need to check up to
    for i in xrange(2, limit):
        mod = 1
        remainder = 0
        for j in xrange(length):
            remainder += mod*a[length - j - 1]
            mod = (mod * n) % i
        if remainder % i == 0:
            return i
    return False

def check_works(a, k):#input a is a list, check for divisors less than k
    return_list = []
    for i in xrange(2, 11):
        divisor = find_divisor(a, i, k)
        if divisor==False:
            return False
        else:
            return_list.append(divisor)
    return return_list

def find_codes(n, j):
    if n==2:
        return False
    return_list = []
    test = [1] + [0 for x in xrange(n-2)] + [1]
    number_to_list = {} #map number to a unique binary coin
    number_works = {} #says if codin corresponding to number works or not
    for i in xrange(2**(n-2)):
        number_to_list[i] = list(test)
        divisors = check_works(test, 100) #100 is arbitrary, first only check divisors <100 to reduce check time
        if divisors!=False:
            coin = ''.join([str(b) for b in test])
            chain = [coin] + divisors
            return_list.append(chain)
            if len(return_list)==j:
                return return_list #already have a list long enough
            number_works[i] = "YES"
        else:
            number_works[i] = "NOT SURE"
        for k in xrange(1, n-1):
            if test[k]==0:
                test[k]=1
                break
            else:
                test[k]=0
    for i in xrange(3, n/2 + 2):
        limit = 10**i #gradually increase the range to check divisor
        for k in xrange(2**(n-2)):
            if number_works[k]=="NOT SURE":
                test = number_to_list[k]
                divisors = check_works(test, limit)
                if divisors != False:
                    coin = ''.join([str(b) for b in test])
                    chain = [coin] + divisors
                    return_list.append(chain)
                    if len(return_list)==j:
                        return return_list
                number_works[k] = "YES"
    return False #return false if we cannot find that many working coins of length n

def convert_list_to_string(return_list):
    return_string = ''
    for i in xrange(len(return_list)):
        for k in xrange(len(return_list[i])):
            return_string = return_string + str(return_list[i][k])
            if k != len(return_list[i])-1:
                return_string = return_string + " "
        if i != len(return_list)-1:
            return_string = return_string + "\n"
    return return_string

a = int(f.readline())
overall = []
for i in xrange(a):
    b = f.readline().strip().split(" ")
    c = convert_list_to_string(find_codes(int(b[0]), int(b[1])))
    overall.append(c)
    print c

for i in xrange(1, a+1):
    output = "Case #" + str(i) + ":\n" + overall[i-1]
    fo.write(output)
    fo.write('\n')

