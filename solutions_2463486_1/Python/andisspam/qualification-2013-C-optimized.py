import math
import numpy as np

def is_palindrome(number):
    str_number = str(number)
    return str_number == str_number[::-1]

palindromes = np.load('palindromes.npy')

f_in = open('qualification-2013-C-large1.dat', 'r')
n = int(f_in.readline())
f_out = open('qualification-2013-Copt.out', 'w')

for i in range(n):
    a, b = [int(item) for item in f_in.readline().strip().split(' ')]
    count = 0
    # start index on the left, end index on the right
    index_a = np.searchsorted(palindromes, [a**.5], side = 'left')
    index_b = np.searchsorted(palindromes, [b**.5], side = 'right')
    for number in palindromes[index_a:index_b]:
        if is_palindrome(number**2):
            count += 1
    f_out.write('Case #%i: %s\n' % (i+1, count))
