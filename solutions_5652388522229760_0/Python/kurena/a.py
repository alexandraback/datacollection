def solve(n):
  if n==0: return "INSOMNIA"
  a=set([])
  for i in range(1,10000):
    s=list(str(n*i))
    a|=set(s)
    if len(a)==10:
      return i*n
testcase = input()
for i in range(testcase):
    print "Case #"+str(i+1)+":",
    print solve(input())
