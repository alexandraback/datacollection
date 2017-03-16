'''
Prog-C; Round-1C.

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
@memoized
def findsubsets(S,m):
    return set(itertools.combinations(S, m))

##############################################################################
# This part would contain the logic for solving actual puzzle.
def solve_puzzle(boxes, toys):
    #print boxes, toys
    
    ans = 0
    while(len(boxes) > 0 and len(toys) > 0):
        n_b = boxes[1]
        n_t = toys[1]
        
        if (n_b == n_t):
            min = boxes[0]
            if toys[0] < min:
                min = toys[0]
            boxes[0] = boxes[0] - min
            if boxes[0] == 0:
                boxes = boxes[2:]
            toys[0] = toys[0] - min
            if toys[0] == 0:
                toys = toys[2:]
            ans += min
        else:
            result1 = solve_puzzle(boxes[2:], toys)            
            result2 = solve_puzzle(boxes, toys[2:])
            #print ans, result1, result2
            if result1 > result2:
                return ans + result1
            else:
                return ans + result2    
    
    return ans
##############################################################################
def main():
    # Large Files. 
    in_file_name = "C-large.in"
    out_file_name = "C-large.out"
    
    # Code for Reading and writing small Files.
    in_file_name = "C-small-attempt0.in"
    out_file_name = "C-small-attempt0.out"
    
    # Test Input.
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    lines = reader.readlines()
    index = 0
    case_no = 1
    for i in range(int(lines[index])):
        index += 1
        index += 1
        boxes = lines[index].strip()
        index += 1
        toys = lines[index].strip()
        
        boxes = boxes.split(" ")
        toys = toys.split(" ")
    
        boxes = map(lambda x: int(x), boxes)
        toys = map(lambda x: int(x), toys)
    
        result = solve_puzzle(boxes, toys)
        
        printit = "Case #" + str(case_no)+ ": " + str(result)
        #print printit 
        writer.write(printit + "\n")
        case_no += 1
        #writer.write("Case #" + str(case_no+1)+ ": " + str(result) + "\n")  
    writer.close()
    
    
##############################################################################
if __name__== "__main__":
    main()