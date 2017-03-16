import sys, random, math

def automain(fn):
  if __name__ == '__main__':
    sys.exit(fn(*sys.argv[1:]))

def int_line(file):
  result = [int(x) for x in file.readline().strip().split()]
  if not result:
    raise Exception("int_line found no ints")
  if len(result) == 1:
    return result[0]
  return result

def memoize(f):
  """ Memoization decorator for functions taking one or more arguments. """
  class memodict(dict):
    def __init__(self, f):
      self.f = f
    def __call__(self, *args):
      return self[args]
    def __missing__(self, key):
      ret = self[key] = self.f(*key)
      return ret
  return memodict(f)

import string

alphabet = string.ascii_lowercase
consonants = ''.join(x for x in alphabet if x not in 'aeiou')

def consonant_count(name, n):
  if len(name) < n:
    return False
  for i in range(len(name) - n+1):
    if all(name[j] in consonants for j in range(i, i+n)):
      return True
  return False

def substrings(string):
  for start in range(len(string)):
    for end in range(start, len(string)):
      yield string[start:end+1]
                            
def powerset(iterable):
  "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
  s = list(iterable)
  return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def DoCase(file):
  line = file.readline().strip().split()
  name = line[0]
  n = int(line[1])
  return sum(int(consonant_count(sub, n)) for sub in substrings(name))

@automain
def main(filename = None):
  if filename is None:
    print("SPECIFY FILE NAME!\n"*5)
    return 1
    # file = sys.stdin

  with open(filename) as file:
    case_count = int_line(file)
    for case in range(case_count):
      print('Case #{}: {}'.format(case+1, DoCase(file)))
