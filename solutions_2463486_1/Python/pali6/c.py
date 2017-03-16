from itertools import product 
from math import ceil, sqrt

n = int(input())

def is_palindrome(num):
    return str(num) == ''.join(list(reversed(str(num))))

def do_case():
    a, b = map(int, input().split())
    a_length = len(str(int(sqrt(a))))
    b_length = len(str(ceil(sqrt(b))))
    found = 0
    for length in range(a_length, b_length+1):
        combinations = list(product([0,1,2], repeat=ceil(length/2)))
        if length == 1:
            combinations = combinations + [(3,)]
        for combination in combinations:
            if length % 2 == 0:
                root = ''.join(map(str, combination)) + ''.join(reversed(list(map(str, combination))))
            else:
                root = ''.join(map(str, combination)) + ''.join(reversed(list(map(str, combination))[:-1]))
            root = int(root)
            num = root ** 2
            if is_palindrome(int(num)) and b >= num >= a:
                found += 1
    return found


for i in range(n):
    print("Case #{}: {}".format(i+1, do_case()))
