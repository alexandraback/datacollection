# Run with Python 3.2

import math, sys

input_filename = "Csmall.txt"

def nextSquare(x):
    """Returns lowest square number >= x"""
    return math.ceil(x**0.5)**2

def prevSquare(x):
    """Returns highest square number <= x"""
    return math.floor(x**0.5)**2

def checkInt(x):
    assert x == int(x), "Not an integer"
    return int(x)

def isPalindrome(x):
    """Returns True if the number is a palindrome"""
    x = str(checkInt(x))
    return x == x[::-1]

def solve(start, end):
    start = checkInt(nextSquare(start)**0.5)
    end = checkInt(prevSquare(end)**0.5)
    n = 0
    for k in range(start, end+1):
        if isPalindrome(k) and isPalindrome(k**2):
            n += 1
    return n

with open(input_filename, "r") as infile:
    with open("output.txt", "w") as sys.stdout:
        numCases = int(infile.readline())
        for case in range(1,numCases+1):
            start, end = infile.readline().replace("\n","").split(" ")
            start = int(start)
            end = int(end)
            print("Case #%i: %i" % (case, solve(start, end)))
            solve(start, end)

#solve(5178327731, 10**20)


