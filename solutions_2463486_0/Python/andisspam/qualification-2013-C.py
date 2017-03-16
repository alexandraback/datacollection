import math
def is_palindrome(number):
    str_number = str(number)
    return str_number == str_number[::-1]

f_in = open('C-small-attempt0.in', 'r')
n = int(f_in.readline())
f_out = open('qualification-2013-C.out', 'w')

for i in range(n):
    a, b = [int(item) for item in f_in.readline().strip().split(' ')]
    count = 0
    for number in xrange(int(math.ceil(a**.5)), int(b**.5)+1):
        if is_palindrome(number) and is_palindrome(number**2):
            count += 1
    f_out.write('Case #%i: %s\n' % (i+1, count))
