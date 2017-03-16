class memoized(object):
  def __init__(self, func):
    self.func = func
    self.cache = {}
  def __call__(self, *args):
    if args in self.cache:
      return self.cache[args]
    else:
      value = self.func(*args)
      self.cache[args] = value
      return value

def lenfun(instr):
  count = 0
  maximum = 0
  for letter in instr:
    if letter not in vowels:
      count += 1
    else:
      maximum = max(count,maximum)
      count = 0
  maximum = max(count,maximum)
  return maximum

times  = int(raw_input())
for time in xrange(times):
  word, N = raw_input().split()
  N = int(N)
  count = 0
  vowels = set(['a','e','i','o','u'])
  for start in xrange(len(word)):
    for end in xrange(start+1, len(word)+1):
      temp = word[start:end]
      if lenfun(temp) >= N:
        count += 1
  print "Case #%d:" % (time+1),count
      
