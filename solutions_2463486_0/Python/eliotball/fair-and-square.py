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

def fair_and_square(lower_bound, upper_bound):
    #start = time.time()
    palindromes_iter = palindromes(1, upper_bound)
    palindromes_hash = dict((i, True) for i in palindromes(lower_bound, upper_bound))
    total = 0
    for palindrome in palindromes_iter:
        if str(int(palindrome)**2) in palindromes_hash:
            total += 1
    #print(time.time() - start)
    return total

fin = open("input.txt", "r")
fout = open("output.txt", "w")

t = int(fin.readline())

for i in range(t):
    bounds = list(map(int, fin.readline().split(" ")))
    print(list(bounds))
    fout.write("Case #" + str(i + 1) + ": " + str(fair_and_square(bounds[0], bounds[1])) + "\n")

fin.close()
fout.close()
