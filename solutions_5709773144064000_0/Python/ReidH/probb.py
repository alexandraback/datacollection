
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

def with_farm(cps, cookies, target, farm_price, cps_bonus):
  cookies -= farm_price
  cps += cps_bonus 
  return without_farm(cps, cookies, target)

n = ri()
for x in range(n):
  fo = rid()
  farm_price = fo[0] #farm price
  cps_bonus = fo[1] #extra cookies per second
  target = fo[2] #target

  total_cps = 2.0
  total_cookies = 0

  total_seconds = 0.0

  while total_cookies < target:
    # how long until i can buy a farm
    can_afford_farm = total_cookies >= farm_price
    til_farm = without_farm(total_cps, total_cookies, farm_price)
    if til_farm < 0:
      til_farm = 0.0
    wf = without_farm(total_cps+cps_bonus, 0, target) + til_farm
    wof = without_farm(total_cps, total_cookies, target)


    if wf < wof:
      if not can_afford_farm:
        total_seconds += til_farm
        total_cookies = farm_price

      total_cookies -= farm_price
      total_cps += cps_bonus

    else:
      total_seconds += wof
      total_cookies = target


  print 'Case #%s:'%(x+1), total_seconds
      
