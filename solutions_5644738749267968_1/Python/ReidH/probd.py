
def ri():
  return int(raw_input())

def rd():
  return float(raw_input())

def rs():
  return raw_input()

def ril():
  return map(int, raw_input().split())

def rid():
  return map(float, raw_input().split())

def rsl():
  return map(str, raw_input().split())

def without_farm(cps, cookies, target):
  return (target-cookies)/cps

def wins(a, b):
  w = 0
  p = 0

  while p < len(b) and a[0] < b[p]:
    p += 1

  ap = 0
  while p < len(b) and ap < len(b):
    if a[ap] > b[p]:
      w += 1
    else:
      p += 1

    p += 1
    ap += 1

  return w


def paly_fair(a, b):
  ai = 0;
  bi = 0;

  while ai < len(a) and bi < len(b):
    while bi < len(b) and b[bi] < a[ai]:
      bi += 1


    if bi >= len(b):
      return len(a) - ai

    ai += 1
    bi += 1

  return len(a) - ai


def play_unfair(a, b):
#ascending
  wins = 0

  at = len(a)-1
  bt = len(b)-1
  ab = 0
  bb = 0
  
  for round in range(len(a)):
    if b[bt] > a[at]:
      ab += 1
      bt -=1
    else:
      wins += 1
      at -= 1
      bt -= 1

  return wins

n = ri()

for x in range(n):
  foo = ri()
  a = rid()
  b = rid()
  a_asc = sorted(a)
  b_asc = sorted(b)
  a_des = list(reversed(a_asc))
  b_des = list(reversed(b_asc))

  print 'Case #%s:'%(x+1), play_unfair(a_asc, b_asc), paly_fair(a_asc, b_asc)

