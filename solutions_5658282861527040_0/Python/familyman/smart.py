# hey! did you ever see anything this beautiful??

"""


consider some place i in the bit string


if 2**i > k then both a and b must be set here

  in which case we have
    arem <= A - 2**i
    brem <= B - 2**i

    so we will continue for 2**ja <= arem
    so we will continue for 2**jb <= brem


for i

not_possible
all_one = may choose either 0 or 1
unbounded = must choose max N[i]

if chooses 1 with unbounded still unbounded
if chooses 0 with unbounded no_bound
if chooses x with nobound nobound

"""


from itertools import *
from random import *
import sys


_input = sys.stdin.read().split()[::-1]
I = lambda: int(_input.pop())




def solve_one():
  aa, bb, kk = I()-1, I()-1, I()-1

  A = [int(x) for x in bin(aa)[2:]]
  B = [int(x) for x in bin(bb)[2:]]
  K = [int(x) for x in bin(kk)[2:]]
  N = max(len(A), len(B), len(K))

  while len(A) < N: A.insert(0, 0)
  while len(B) < N: B.insert(0, 0)
  while len(K) < N: K.insert(0, 0)

  def opts(i, a_unbounded, b_unbounded, k_unbounded):
    if i == N:
      return 1

    maya1 = A[i] == 1 or a_unbounded
    mayb1 = B[i] == 1 or b_unbounded
    mayk1 = K[i] == 1 or k_unbounded

    res = 0
    for a_opt, b_opt in product([0, 1], [0,1]):
      k_opt = a_opt & b_opt

      a_next_unbounded = a_opt < A[i] or a_unbounded
      b_next_unbounded = b_opt < B[i] or b_unbounded
      k_next_unbounded = k_opt < K[i] or k_unbounded

      if a_opt == 1 and not maya1:
        continue
      if b_opt == 1 and not mayb1:
        continue
      if k_opt == 1 and not mayk1:
        continue

      res += opts(i+1, a_next_unbounded, b_next_unbounded, k_next_unbounded)

    return res

  vs = 0
  for a in range(aa+1):
    for b in range(bb+1):
      if (a&b)<=kk:
        vs += 1

  res = opts(0, False, False, False)
  assert vs == res
  return res



for i in range(1, I()+1):
    print 'Case #%d: %d' % (i, solve_one(),)
