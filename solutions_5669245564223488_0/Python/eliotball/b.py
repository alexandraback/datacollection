def perms(xs):
  if len(xs) == 0:
    yield []
  else:
    for head_i in xrange(len(xs)):
      for tail in perms(xs[:head_i] + xs[head_i+1:]):
        yield [xs[head_i]] + tail

def possible(cars):
  train = "".join(cars)
  # Check train
  seen = { train[0]: True }
  ok = True
  for letter_i in range(1, len(train)):
    if train[letter_i] in seen and train[letter_i] != train[letter_i - 1]:
      ok = False
    else:
      seen[train[letter_i]] = True
  return ok

def count(cars):
  # Find a boundary letter (quadratic time)
  letter = None
  for left_i in xrange(len(cars)):
    if letter != None:
      break
    for right_i in xrange(len(cars)):
      if right_i == left_i:
        continue
      if cars[left_i][0] == cars[right_i][-1]:
        letter = cars[left_i][0]
  if letter != None:
    # There is a boundary letter to deal with
    # Count the number of trains starting and ending with the same letter
    monos = []
    for car_i in xrange(len(cars)):
      if cars[car_i][0] == letter and cars[car_i][-1] == letter:
        # Check if this car has other letters in the middle
        for mid in cars[car_i][1:-1]:
          if mid != cars[car_i][0]:
            return 0
        monos += [car_i]
    # Construct the joined car
    joined_car = ""
    left_i = None
    # Check if there is a right without a left
    for car_i in xrange(len(cars)):
      if cars[car_i][0] != letter and cars[car_i][-1] == letter:
        if left_i != None:
          return 0  # There were two left-cars
        left_i = car_i
        joined_car = cars[car_i]
    # Put the other cars in the middle
    for mono_i in monos:
      joined_car += cars[mono_i]
    right_i = None
    # Check if there is a left without a right
    for car_i in xrange(len(cars)):
      if cars[car_i][0] == letter and cars[car_i][-1] != letter:
        if right_i != None:
          return 0  # There were two right-cars
        right_i = car_i
        joined_car += cars[car_i]
    # Construct the new problem
    new_cars = [joined_car] + [cars[i] for i in xrange(len(cars))
                                 if i != left_i and i != right_i and i not in monos]
    return (count(new_cars) * fac(len(monos))) % 1000000007
  else:
    # There are no boundary letters - check that the arrangement is possible
    if possible(cars):
      # Return n factorial modulo 1,000,000,007
      return fac(len(cars))
    else:
      return 0

def fac(n):
  if n == 0:
    return 1
  res = 1
  for i in xrange(1, n + 1):
    res = (res * i) % 1000000007
  return res

if __name__ == "__main__":
  for case in range(int(raw_input())):
    raw_input() # Number of cars
    print "Case #" + str(case + 1) + ": " + str(count(raw_input().split(" ")))
