INPUT_FILE = 'sample.in'
INPUT_FILE = 'C-small-1-attempt0.in'
INPUT_FILE = 'C-small-2-attempt0.in'

def time_until_finish(hiker):
  starting_point, time = hiker
  return ((360 - starting_point) * time) / 360.0

def num_finishes(time, hiker):
  old_time = time
  time -= time_until_finish(hiker)
  num = 1
  if time < 0:
    return 0
  num += time / hiker[1]

  return int(num)


def solve_case(hikers):
  hikers.sort(key=time_until_finish)
  overlaps = []
  for i in range(len(hikers)):
    finish_time = time_until_finish(hikers[i])
    overlaps.append(0)
    for j in range(i):
      overlaps[i] += num_finishes(finish_time, hikers[j]) - 1
  best_result = float('inf')
  for num_overtake in range(len(hikers)):
    result = num_overtake + overlaps[-(num_overtake+1)]
    best_result = min(result, best_result)
  return best_result





with open(INPUT_FILE, 'r') as f:
  num_cases = int(f.readline())
  for i in range(num_cases):
    num_groups = int(f.readline())
    hikers = []
    for _ in range(num_groups):
      starting_point, num_hikers, time = [int(x) for x in f.readline().split(' ')]
      for x in range(num_hikers):
        hikers.append((starting_point, time + x))
    print 'Case #{0}:'.format(i + 1), solve_case(hikers)
