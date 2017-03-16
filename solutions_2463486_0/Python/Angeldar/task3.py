# CodeJam 2013
# Task C

def isPalindrome(num):
  num = str(num)
  length = len(num)
  for i in range(length):
    if num[i]!=num[length-1-i]:
      return False
  return True

def findPalindromes(start, finish):
  f = open('pals','w')
  i = start
  while i<= finish:
    if isPalindrome(i):
      f.write(str(i)+'\n')
    i+=1
  f.close()

def resFile():
  f = open('pals')
  pals = open('pals_res','w')
  data = [int(t) for t in f.readlines()]
  for i in data:
    if i**2 in data:
      pals.write(str(i**2)+'\n')

def solve():
  f = open('in')
  out = open('out','w')
  data = [1,4,9,121,484]

  T = int(f.readline())
  for i in range(T):
    a, b = [int(t) for t in f.readline().split()]
    res=0
    for j in data:
      if a<=j<=b:
        res+=1
    out.write(("Case #%d: " % (i+1))+str(res)+'\n')
  f.close()
  out.close()

print 'Start'
solve()
print 'Done'