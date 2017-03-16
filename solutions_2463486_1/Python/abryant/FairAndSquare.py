import sys
from math import *


def gen_palindrome(n, even):
  chars = list(str(n))
  result = [''] * (2 * len(chars) - (0 if even else 1))
  for i in range(0, len(chars)):
    result[i] = chars[i]
    result[len(result) - 1 - i] = chars[i]
  return int("".join(result))

def is_palindrome(n):
  chars = list(str(n))
  for i in range(0, len(chars) // 2):
    if chars[i] != chars[len(chars) - 1 - i]:
      return False
  return True

if __name__ == "__main__":
  tests = int(sys.stdin.readline())
  for test in range(1, tests + 1):
    a, b = [int(x) for x in sys.stdin.readline().split()]
    count = 0
    sa, sb = floor(sqrt(a)), ceil(sqrt(b))
#    print("sa=" + str(sa) + ", sb=" + str(sb))
    start_digits, end_digits = len(str(sa)), len(str(sb))
    for digits in range(start_digits, end_digits + 1):
      gen_digits = ceil(digits / 2)
      start = 10 ** (gen_digits - 1)
      if digits == start_digits:
        start = sa // (10 ** floor(digits / 2))
      end = (10 ** gen_digits) - 1
      if digits == end_digits:
        end = sb // (10 ** floor(digits / 2))
#      print("start=" + str(start) + " end=" + str(end))
      for i in range(start, end + 1):
        palindrome = gen_palindrome(i, digits % 2 == 0)
        squared = palindrome * palindrome
        if a <= squared and squared <= b and is_palindrome(squared):
#          print("Found: " + str(palindrome) + " squared = " + str(palindrome*palindrome))
          count += 1
    print("Case #" + str(test) + ": " + str(count))

