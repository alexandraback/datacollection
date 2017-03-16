import sys

def canbemade(num, best):
  sub = (best-2)*2
  if (sub < 0): 
    sub = 0
  if ((num - sub) >= best):
    return True
  else:
    return False
 
def natural(num, best):
  sub = (best-1)*2 
  if (sub < 0): 
    sub = 0
  if ((num - sub) >= best):
    return True
  else:
    return False 

if __name__ == '__main__':
  inputs = raw_input()
  cnt = 0
  for i in range(0, int(inputs)):
    l = raw_input().split(" ")
    people = int(l[0])
    surprises = int(l[1])
    best = int(l[2])
    count = 0
    for j in l[3:]:
      if (natural(int(j), best)):
        count = count + 1
        continue
      if (surprises > 0): 
        if (canbemade(int(j), best)):
          surprises = surprises-1
          count = count + 1
          continue
    cnt = cnt + 1
    print "Case #" + str(cnt) + ": " +  str(count)  
