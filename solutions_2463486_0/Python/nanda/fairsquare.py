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
fns =  [1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
100000020000001,
100220141022001,
102012040210201,
102234363432201,
121000242000121,
121242363242121,
123212464212321,
123456787654321,
400000080000004,
10000000200000001,
10002000300020001,
10004000600040001,
10020210401202001,
10022212521222001,
10024214841242001,
10201020402010201,
10203040504030201,
10205060806050201,
10221432623412201,
10223454745432201,
12100002420000121,
12102202520220121,
12104402820440121,
12122232623222121,
12124434743442121,
12321024642012321,
12323244744232321,
12343456865434321,
12345678987654321]
##############################################################################
# This part would contain the logic for solving actual puzzle.
import math
#@memoized
def is_pal(no):
    no = str(no)
    rev = no[::-1]
    
    if no == rev:
        return True

#@memoized
def do_magic(x):
    res = is_pal(x)
    if res:
        new_x = math.sqrt(x)
        if str(new_x).endswith(".0"):
            res2 = is_pal(long(new_x))
            if res2:
                print x
                return True

def do_magic2(x):
    res = is_pal(x)
    if res:
        new_x = x * x
        res2 = is_pal(new_x)
        if res2:
            print new_x
            return True
    return False

def solve_puzzle(input):
    input = input.split(" ")
    x = long(input[0])
    #print x
    y = long(input[1])
    #print y
    
    count = 0
    for no in fns:
        if no >= x and no <= y:
            count += 1

    return count
    
#     l_x = math.sqrt(x)
#     if str(l_x).endswith(".0"):
#         l_x = long(l_x)
#     else:
#         l_x = long(l_x) + 1
#         
#     l_y = long(math.sqrt(y))
#     count = 0
#     while(l_x <= l_y):
#         #print l_x, "NN"
#         if do_magic2(l_x):
#             count += 1
#         l_x += 1
#         
#     return count
    
#     count = 0
#     while(x <= y):
#         if do_magic(x):
#             count += 1
#         x += 1
#     return count    

##############################################################################
def main():
    # Test Input
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    # Code for Reading and writing.
    # Small Files.
    in_file_name = "C-small-attempt0.in"
    #in_file_name = "Test.in"
    out_file_name = "C-small-attempt0.out"
    
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