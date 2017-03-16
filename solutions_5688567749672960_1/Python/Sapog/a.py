#!/usr/bin/python3
T = int(input())
for t in range(1, T+1):
  N = int(input())
  n = N
  result1 = 0
  while n > 20:
    s = str(n)
    b = s == '1' + '0' * (len(s) -2) + '1'
    if not b and s[-1] == '1':
      if len(s) > 2:
        steps = int(s[len(s)//2:-1] + '0')
        result1 += steps
        n -= steps
       # if steps: print (n)
      if str(n)[::-1] != str(n):
        n = int(str(n)[::-1])
        result1 += 1
        #print(n)
    elif b:
      steps = int(s[1:]) + 1
      result1 += steps
      n -= steps
      #print(n)
    else:
      n -= 1
      result1 += 1
      #print(n)
  result1 += n
  print('Case #{}: {}'.format(t, result1))

