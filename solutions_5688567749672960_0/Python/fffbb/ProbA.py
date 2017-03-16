import sys

f = open(sys.argv[1], 'r')

def revnum(n) :
  strn = str(n)
  temp = ''
  for i in range(len(strn)) :
    temp += strn[-(i + 1)]
  return int(temp)

T = int(f.readline())
for t in range(1, T + 1):
  print('Case #{0}:'.format(t), end = ' ')
  n = int(f.readline())

  if n < 20 :
    print(n)
  else :
    i = 10
    total = 10
    while True :
      if len(str(n)) > len(str(i)) :
        if len(str(i)) % 2 == 1 :
          total += int('10' + ('9' * (len(str(i)) // 2)))
        else :
          total += int('1' + ('9' * (len(str(i)) // 2)))
        i *= 10
      else :
        b = 10 ** (len(str(i)) // 2)
        n2 = (n // b) * b
        if n2 > i:
          total += ((revnum(n2 + 1) - i) + (n % b))
        else :
          total += (n - i)
        break
    print(total)
