'''
Prog-C; Round-1B.

@author: nanda
'''
##############################################################################
import string

##############################################################################
class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned 
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      try:
         return self.cache[args]
      except KeyError:
         value = self.func(*args)
         self.cache[args] = value
         return value
      except TypeError:
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)

##############################################################################
# Possible digits from the lowest to the highest
DIGITS = '%s%s' % (string.digits, string.lowercase)

@memoized
def baseencode(num, base):
    result = 0
    positive = True
    # If a number is negative let's remove the minus sign
    if num[0] == '-':
        positive = False
        num = num[1:]
    for i, n in enumerate(num[::-1]):
        # Since 0xff == 0xFF
        n = n.lower()
        result += DIGITS.index(n) * base ** i
    if not positive:
        result = -1 * result
    return result

##############################################################################
import itertools
def findsubsets(S,m):
    return set(itertools.combinations(S, m))

# This part would contain the logic for solving actual puzzle.
def solve_puzzle(input):
    y = input.split(" ")[1:]
    
    points = map(lambda x: int(x), y)
    all = []
    print points
    for i in range(len(points)):
        x = findsubsets(points, i+1)
        all.extend(list(x)) 

    for x in all:
        sum1 = sum(x)
        s1 = x
        for y in all:
            if sum(y) == sum1 and x != y:
                return (x, y)
  
##############################################################################
def main():
    # Large Files. 
    in_file_name = "C-large.in"
    out_file_name = "C-large.out"
    
    # Code for Reading and writing small Files.
    in_file_name = "C-small-attempt0.in"
    out_file_name = "C-small-attempt0.out"
    
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    reader.readline()
    for case_no, input in enumerate(reader):
        result = solve_puzzle(input)
        print result
        writer.write("Case #" + str(case_no+1)+ ": " + "\n")
        for a in result:
            b = list(a)
            c = map(lambda x: str(x), b)
            writer.write(" ".join(c) + "\n")  
    writer.close()
    
##############################################################################
if __name__== "__main__":
    main()