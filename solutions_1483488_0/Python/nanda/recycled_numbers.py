'''
Recycled numbers. CodeJam-2012

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
# This would return the list of cycles for a given numbers.
@memoized
def get_cycles(n):
    cycles = []
    div = 10
    while div < n:
        a = n / div
        b = n % div
        c = int(str(b) + str(a))
        cycles.append(c)
        div = div * 10
    return list(set(cycles))    

##############################################################################
# This part would contain the logic for solving actual puzzle.
def solve_puzzle(input):
    A, B = input.split(" ")
    A = int(A)
    B = int(B)
    
    pairs = 0
    for n in range(A, B):        
        cycles = get_cycles(n);
        for m in cycles:
            if m > n and m <= B:
                #print n,m
                pairs = pairs + 1;
    
    return pairs 
  
##############################################################################
def main():
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    # Code for Reading and writing.
    # Small Files.
    in_file_name = "C-small-attempt0.in"
    out_file_name = "C-small-attempt0.out"
    
    # Large Files. 
    #in_file_name = "A-large-practice.in"
    #out_file_name = "A-large-practice.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    reader.readline()
    for case_no, input in enumerate(reader):
        result = solve_puzzle(input)
        writer.write("Case #" + str(case_no+1)+ ": " + str(result) + "\n")   
    writer.close()
    
##############################################################################
if __name__== "__main__":
    main()