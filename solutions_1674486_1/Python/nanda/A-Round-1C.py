'''
Prog-A; Round-1C.

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
def solve_puzzle(input):
    #print input
    marked_map = {}
    for i in range(len(input)):
        i += 1
        
        marked_map = {}        
        marked_map[str(i)] = str(i)
        ans = start_cycle(str(i), input, marked_map)
        if ans == "Yes":
            return ans
    return "No"

def start_cycle(i, input, marked_map):
    queue = []
    to_push = input[int(i)-1]
    
    for ele in to_push:
        queue.append(ele)
    
    #print queue, marked_map
    while(len(queue) > 0):
        poped = queue[0]
        if poped in marked_map:
            return "Yes"
        queue = queue[1:]        
        marked_map[poped] = i
                
        poped = int(poped) - 1
        to_push = input[poped]
        for ele in to_push:
            if ele not in marked_map:
                queue.append(ele)
            else:
                return "Yes"        
        #print queue, marked_map
##############################################################################
def main():
    # Large Files. 
    in_file_name = "A-large.in"
    out_file_name = "A-large.out"
    
    # Code for Reading and writing small Files.
    #in_file_name = "A-small-attempt1.in"
    #out_file_name = "A-small-attempt1.out"
    
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
        dg = []
        for j in range(int(lines[index])):
            index += 1
            dg.append(lines[index].strip().split(" ")[1:])
        result = solve_puzzle(dg)
        printit = "Case #" + str(case_no)+ ": " + str(result)
#        print printit 
        writer.write(printit + "\n")
        case_no += 1
        #writer.write("Case #" + str(case_no+1)+ ": " + str(result) + "\n")  
    writer.close()
    
    
##############################################################################
if __name__== "__main__":
    main()