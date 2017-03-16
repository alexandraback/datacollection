from sys import stdin

def is_palindrome(palindrome):
  for i in range(len(palindrome) / 2):
    if palindrome[i] != palindrome[-i-1]:
      return False
  return True

def generate(length, init_len, pre, middle=''):
  global palindromes
  if length > 1:
    start = 1 if length == init_len else 0
    for i in range(start, 10):
      if not generate(length - 2, init_len, pre + str(i)):
        return False
  elif length > 0:
    for i in range(10):
      if not generate(0, init_len, pre, middle=str(i)):
        return False
  else:
    n = int(pre + middle + pre[::-1]) ** 2
    if (n > 100000000000000):
      return False
    if is_palindrome(str(n)):
      palindromes.append(n)
  return True

palindromes = []

for i in range (1, 20):
  if not generate(i, i, ''):
    break

n = int(stdin.readline())
for i in range(n):
  line = stdin.readline().split()
  A = int(line[0])
  B = int(line[1])
  count = 0
  for p in palindromes:
    if A <= p <= B:
      count += 1
  print 'Case #' + str(i + 1) + ':', count

