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
#############################################################################

##############################################################################
# This part would contain the logic for solving actual puzzle.
def is_x_largest(input, x, y):
    no = input[x][y]
    for x in input[x]:
        if x > no:
            return False
    
    return True

def is_y_largest(input, x, y):
    no = input[x][y]
    for row in input:
        if row[y] > no:
            return False
    
    return True
    
def solve_puzzle(input):
    for x, row in enumerate(input):
        for y, no in enumerate(row):
            x_largest = is_x_largest(input, x, y)
            y_largest = is_y_largest(input, x, y)
            
            if not x_largest and not y_largest:
                return "NO"
    return "YES"      

##############################################################################
def main():
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    # Code for Reading and writing.
    # Small Files.
    in_file_name = "B-large.in"
    #in_file_name = "Test.in"
    out_file_name = "B-large.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    cases = int(reader.readline().strip())
    for i in range(cases):
        line = reader.readline().strip().split(" ")
        rows = int(line[0])
        input = []
        for x in range(rows):
            row = reader.readline().strip().split(" ")
            row = map(lambda x: int(x), row)
            input.append(row)
        print input
        result = solve_puzzle(input)
        print result
        writer.write("Case #" + str(i+1)+ ": " + str(result) + "\n")              
        
    writer.close()
    
##############################################################################
if __name__== "__main__":
    main()