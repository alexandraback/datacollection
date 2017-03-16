'''
Tic-Tac CodeJam-2013

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
O = 'O'
X = 'X'
T = 'T'
DOT = '.'
WIN_SUFFIX = " won"
DRAW = "Draw"
NR = "Game has not completed"
def check_if_wins(input, x, y):
    char = input[x][y]
    x_match = True
    y_match = True
    xy_match = True
    for c in input[x]:
        if c not in [T, char,]:
            x_match = False
#            print "x no match"
            break
    
    for i in range(4):
        c = input[i][y]
        if c not in [T, char]:
            y_match = False
#            print "y no match"
            break
     
    if x in [0,3] and y in [0, 3]:
        if x == y:
            for i in range(4):
                c = input[i][i]
                if c not in [T, char]:   
                    xy_match = False
#                    print "xy no match"
                    break
        else:
            x_t = 0
            y_t = 3
            for i in range(4):
                c = input[x_t + i][y_t - i]
                if c not in [T, char]:
#                     print "yx no match"
                    xy_match = False
                    break
    else:
        xy_match = False
                
    if (x_match or y_match or xy_match):
        return True
    else:
        return False 
    

def solve_puzzle(input):
    is_complete = True
    for x, line in enumerate(input):
        for y, char in enumerate(line):
            if char == DOT:
                is_complete = False
            if char in [T, DOT]:
                continue
            result = check_if_wins(input, x, y)
#             print input, input[x][y]
#             print result
            if result:
                return char + WIN_SUFFIX
    if is_complete:
        return DRAW
    else:
        return NR    

##############################################################################
def main():
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    # Code for Reading and writing.
    # Small Files.
    in_file_name = "A-small-attempt0.in"
    out_file_name = "A-small-attempt0.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    reader.readline()
    
    count = 0
    case_no = 0
    input = []
    for line in reader.readlines():
        if line == "\n":
            continue
        input.append(line.strip())
        count = count + 1
        if count == 4:
            case_no += 1
            result = solve_puzzle(input)
#             print input
#             print result
            writer.write("Case #" + str(case_no)+ ": " + str(result) + "\n")
            
            count = 0
            input = []
         
    writer.close()
    
##############################################################################
if __name__== "__main__":
    main()