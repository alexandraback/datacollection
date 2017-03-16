'''
This script would have template for reading and writing files for the google code jam thing.

@author: nanda
'''
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
# This part would contain the logic for solving actual puzzle.
def solve_puzzle(input):
    s, p = input.split(" ")[1:3]
    scores = input.split(" ")[3:]
    
    s = int(s)
    p = int(p)

    ok = p + 2 * (p-1)
    if ok < 0: ok = 0
    ok1 = p + 2 * (p-2)
    if ok1 < 0: ok1 = 1
            
    count = 0
    for score in scores:
        score = int(score)
        if score >= ok:
            count = count + 1
            continue
        if score >= ok1 and s > 0:            
            count = count + 1               
            s = s - 1
    
    return count
  
##############################################################################
def main():
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    # Code for Reading and writing.
    # Small Files.
    #in_file_name = "B-small-attempt0.in"
    #out_file_name = "B-small-attempt0.out"
    
    # Large Files. 
    in_file_name = "B-large.in"
    out_file_name = "B-large.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    reader.readline()
    for case_no, input in enumerate(reader):
        result = solve_puzzle(input.strip())
        writer.write("Case #" + str(case_no+1)+ ": " + str(result) + "\n")   
    writer.close()
    
##############################################################################
if __name__== "__main__":
    main()