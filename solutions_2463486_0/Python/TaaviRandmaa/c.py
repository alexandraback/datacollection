def reverse_number(n, partial=0):
    if n == 0:
        return partial
    return reverse_number(n / 10, partial * 10 + n % 10)

def is_palindrome(i):
  return i == reverse_number(i)

i=1
list = []
while i < 1000:
  if is_palindrome(i) and is_palindrome(i*i):
    list.append(i*i)
  i += 1

with open('C-small-attempt0.in', 'r') as fi:
  with open('out.txt', 'w') as fo:
    cases = int(fi.readline())
    for case in range(1, cases + 1):
      count = 0
      rfrom, rto = fi.readline().rstrip().split(' ')
      rto = long(rto)
      rfrom = long(rfrom)
      for test in list:
        if test >= rfrom and test <= rto:
          count += 1
      fo.write('Case #' + str(case) + ': ' + str(count))
      if case != cases :
        fo.write('\n')
  fo.closed
fi.closed
