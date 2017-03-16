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
  for line in f.readlines():
    num = int(line)
    sq = num**2
    if isPalindrome(sq):
      pals.write(str(sq)+'\n')
    print line
  f.close()
  pals.close()

def solve():
  f = open('in')
  out = open('out','w')
  data = [1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,
        121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,
        40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,
        1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004]
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