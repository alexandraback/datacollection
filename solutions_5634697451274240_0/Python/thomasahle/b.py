import sys, re
read = lambda t=int: list(map(t,sys.stdin.readline().split()))

T, = read()
for testCase in range(T):
   s, = read(str)
   runs = len(re.findall('\++|\-+', s))
   res = runs - int(s[-1] == '+')
   print('Case #{}: {}'.format(testCase+1, res))

