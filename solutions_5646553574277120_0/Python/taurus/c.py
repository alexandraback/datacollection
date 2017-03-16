import itertools
import functools 

def main():
  testcases = int(input())
  for caseNr in range(1, testcases+1):
    c,d,v = map(int, input().split())
    ls = list(map(int, input().split()))
    print("Case #%i: %i" % (caseNr, solve(c,d,v,ls)))
    
def solve(c,d,v,ls):
  s = set(ls)
  added = 0
  for p in combinations(s):
    s.add(functools.reduce(add, p, 0))
  # print(s)
  while 1:
    s = set(filter(lambda x: x <= v, s))
    # print(s)
    if len(s) == v:
      return added
    else:
      m = findMinMissing(sorted(list(s)),v)
      sCopy = set(s)
      # print(sCopy, m)
      for e in sCopy:
        s.add(e + m)
      s.add(m)
      added += 1 
  
def add(a,b):
  return a + b
  
def combinations(ls):
  s = set()
  for l in range(1, len(ls)+1):
    for subset in itertools.combinations(ls, l):
      s.add(subset)
  return s
  
def findMinMissing(ls,v):
  exp = 1
  for i in range(0, v):
    if i >= len(ls):
      return exp
    elif ls[i] != exp:
      return exp
    else:
      exp += 1
    
if __name__ == "__main__":
  main()
    