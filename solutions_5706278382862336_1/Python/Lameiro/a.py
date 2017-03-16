from pprint import pprint
from itertools import product
import sys
from fractions import Fraction

powers_of_two = {(2**i) for i in xrange(100)}
epsilon = 1e-13

#def is_power_of_two(x):
#    for o in powers_of_two:
#        if o <= x+epsilon:
#            return True
#    return False

def read_list_of(numtype):
    x = raw_input()
    x = x.split('/')
    return map(numtype, x)


def calculate(p,q):
    f = Fraction(p,q)
    if f.denominator not in powers_of_two:
        return "impossible"

    p = p*1.0
    count = 1
    r = p/q
    r = r*2

    while r < 1:
        r *= 2
        count+=1

    return count

def main():
    for case_number in xrange(int(raw_input())):

        p, q = read_list_of(int)
        result = calculate(p, q)

        print 'Case #%d: %s' % (case_number+1, result)

main()

# print calculate(5,8)
# print calculate(3,8)
# print calculate(1,2)
# print calculate(1,4)
# print calculate(3,4)
# print calculate(2,23)
# print calculate(123,31488)

#Fraction().
# print calculate(['aabc', 'abbc', 'abcc'])