def next_palindrome(n):
    if n == "9" * len(n):
        return "1" + "0" * (len(n) - 1) + "1"
    else:
        return next_palindrome_inside(n)

def next_palindrome_inside(n):
    # Single digits
    if len(n) == 1 and n != "9":
        return str(int(n) + 1)
    elif n == "9" * len(n):
        raise Exception()
    else:
        try:
            return n[0] + next_palindrome_inside(n[1 : -1]) + n[-1]
        except:
            return str(int(n[0]) + 1) + "0" * (len(n) - 2) + str(int(n[-1]) + 1)
        
def palindromes(lower_bound, upper_bound):
    i = "1"
    while int(i) < lower_bound:
        i = next_palindrome(i)
    while int(i) <= upper_bound:
        yield i
        i = next_palindrome(i)

import time
import math

def is_palindrome(n):
    n = str(n)
    if len(n) <= 1:
        return True
    else:
        return n[0] == n[-1] and is_palindrome(n[1:-1])

def fair_and_square(lower_bound, upper_bound):
    #start = time.time()
    total = 0
    for root in palindromes(int(math.sqrt(lower_bound)) - 1, int(math.sqrt(upper_bound) + 1)):
        if is_palindrome(int(root)**2) and int(root)**2 <= upper_bound and int(root)**2 >= lower_bound:
            #print(int(root)**2)
            total += 1
    #print(time.time() - start)
    return total

fin = open("input.txt", "r")
fout = open("output.txt", "w")

t = int(fin.readline())

for i in range(t):
    bounds = list(map(int, fin.readline().split(" ")))
    fout.write("Case #" + str(i + 1) + ": " + str(fair_and_square(bounds[0], bounds[1])) + "\n")

fin.close()
fout.close()
