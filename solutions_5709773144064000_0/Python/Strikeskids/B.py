def case():
  C, F, X = map(lambda x: float(x), input().split(' '))
  production = 2.0
  pretime = 0
  time = -1
  while True:
    time = X/production
    time2 = C/production + X/(F+production)
    if time2 < time:
      pretime += C/production
      production += F
    else:
      break
  return pretime + time


def main():
  for c in range(1, int(input())+1):
    print('Case #'+str(c)+':', case())

if __name__=='__main__': main()