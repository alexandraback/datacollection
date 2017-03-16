
import itertools
import math
#import numpy

def read_word(f):
    return next(f).strip()

def read_int(f, b=10):
    return int(read_word(f), b)

def read_letters(f):
    return list(read_word(f))

def read_digits(f, b=10):
    return [int(x, b) for x in read_letters(f)]

def read_words(f, d=' '):
    return read_word(f).split(d)

def read_ints(f, b=10, d=' '):
    return [int(x, b) for x in read_words(f, d)]

def read_floats(f, d=' '):
    return [float(x) for x in read_words(f, d)]

def read_arr(f, R, reader=read_ints, *args, **kwargs):
    res = []
    for i in range(R):
        res.append(reader(f, *args, **kwargs))
    return res

def solve(solver, fn, out_fn=None):
    in_fn = fn + '.in'
    if out_fn is None:
        out_fn = fn + '.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            T = read_int(fi)
            for i in range(T):
                case = read_case(fi)
                res = solver(case)
                write_case(fo, i+1, res)

################################################################################

def read_case(f):
    (A, B) = read_ints(f)
    return (A, B)

def write_case(f, i, res):
    f.write('Case #%d: '%i)
    f.write('%s'%res)
    f.write('\n')

################################################################################

def is_palindrome(a):
  s = str(a)
  return s==s[::-1]

def to_int(len, sparse):
  ans = 0
  for (val, pos) in set(sparse):
    #assert(pos<=(len-1)/2)
    ans += val*10**pos
    if pos != (len-1-pos):
      ans += val*10**(len-1-pos)
  #assert(is_palindrome(ans))
  return ans

def gen_sparse(len):
  # 11111, etc
  for i in range(0, (len-1)/2+1):
    for j in range(0, (len-1)/2+1):
      for k in range(0, (len-1)/2+1):
        for l in range(0, (len-1)/2+1):
          yield [(1,0), (1, i), (1, j), (1, k), (1, l)]
  # 211, 21
  for i in range(0, (len-1)/2+1):
    for j in range(1, (len-1)/2+1):
      yield [(1,0), (1, i), (2, j)]
  # 12
  for i in range(1, (len-1)/2+1):
    yield [(2,0), (1, i)]

  # 2
  yield [(2,0)]

  # 3
  yield [(3,0)]

def solve_small(case):
    (A, B) = case
    return len([x for x in fs if x>=A and x<=B])

solve_large = solve_small

fs = set()

def test():
  sparse = [(1,0), (1,3), (2,4)]
  a = to_int(9, sparse)
  print a, a*a
  print is_palindrome(a*a)
  
def precompute(upper):
  for digits in range(1, upper+1):
    print digits
    for s in gen_sparse(digits):
      v = to_int(digits, s)
      if is_palindrome(v*v):
        #print v, v*v
        fs.add( v*v )
    print sorted(fs)

#test()
precompute(8) # 7 is enough
solve(solve_small, 'C-large-1')

#precompute(51) # 50 is enough
#solve(solve_small, 'C-large2')
