# import sys
# sys.setrecursionlimit(100000)
# dynamic programming

def fun(A, motes):
  # print A, motes
  if A == 1:
    return len(motes)
  if len(motes) == 0:
    return 0
  first = motes[0]
  if first < A:
    A = first + A
    # print A
    del motes[0]
    return fun(A, motes)
  else:
    if first == 1:
      return len(motes)
    removes = len(motes)
    other = fun(A, [A - 1] + motes)
    return min([removes, other + 1])


def main():
  n = int(input())
  for i in range(n):
    A, z = [int(x) for x in raw_input().split()]
    motes = sorted([int(x) for x in raw_input().split()])
    # print A
    # print motes
    print 'Case #%s: %s' % (i + 1, fun(A, motes) )
    # print 
    
    # c = 0
    # for m in motes:
    #   if m < A:
    #     A = m + A
    #   else:
    #     # at this point, i can remove all ahead
    #     c += 0

    # print 'Case #%s: %s' % (i + 1, answers[p] )
main()