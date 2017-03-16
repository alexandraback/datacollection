def time_to_get(amount, rate):
  return amount / rate

def solve(farm_cost, farm_rate, target):
  last = target / 2.0
  farm_count = 0
  farm_time = 0.0
  while True:
    farm_count += 1
    farm_time += farm_cost / (2.0 + (farm_count - 1) * farm_rate)
    this = farm_time + time_to_get(target, 2.0 + farm_count * farm_rate)
    if this > last:
      return round(last, 7)
    last = this

for i in range(int(raw_input())):
  problem = [float(value) for value in raw_input().split(" ")]
  print "Case #" + str(i + 1) + ": " + str(solve(problem[0], problem[1], problem[2]))
