'''
Prog-A; Round-1B.

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
# This part would contain the logic for solving actual puzzle.
def solve_puzzle(input):
    y = input.split(" ")[1:]
    
    points = map(lambda x: int(x), y)

    s2 = sum(points) 
    s = s2 * 2  
    
    magic = s * 1.0 /len(points)
    ans = []
    count = 0
    ns = s
    for p in points:
        if p >= magic:
            ans.append(str(0.0))
            ns  -= p
        else:
            ans.append(-1)
            count += 1
    
    nmagic = ns * 1.0 / count
    for i, p in enumerate(points):
        if ans[i] == -1:
            x = (nmagic - p) * 100.0 / s2
            ans[i] = str(x)
    
#    s3 = 0
#    xx = len(points)
#    for p in points:
#        x = (magic - p) * 100.0 / s2
#        if x <= 0:
#            s3 += x
#            xx -= 1
#            x = 0.0
#        if x >= 100.0:
#            x = 100.0
#        ans.append(x)
#    
#    if s3 != 0:
#        s3 = s3 / xx
#        for i, a in enumerate(ans):
#            if a > 0.0:
#                ans[i] += s3
#            ans[i] = str(ans[i])
#    else:
#        for i, a in enumerate(ans):
#            ans[i] = str(ans[i])          
#    
    check_sum = 0
    for a in ans:
        check_sum += float(a)
    print check_sum
    return " ". join(ans)    
  
##############################################################################
def main():
    # Large Files. 
    in_file_name = "A-large.in"
    out_file_name = "A-large.out"
    
    # Code for Reading and writing small Files.
    in_file_name = "A-small-attempt1.in"
    out_file_name = "A-small-attempt1.out"
    
    # Test Input.
    #in_file_name = "Test.in"
    #out_file_name = "Test.out"
    
    in_file =  "d:\codejam\problems\\" + in_file_name
    out_file = "d:\codejam\problems\\" + out_file_name
    
    reader = open(in_file)
    writer = open(out_file, 'w')
    
    reader.readline()
    for case_no, input in enumerate(reader):
        result = solve_puzzle(input)
        print "Case #" + str(case_no+1)+ ": " + str(result)
        writer.write("Case #" + str(case_no+1)+ ": " + str(result) + "\n")  
    writer.close()
    
    
##############################################################################
if __name__== "__main__":
    main()