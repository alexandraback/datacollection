
import itertools

def can_solve(perm, flights):
  stack = [perm[0]]

  for x in perm[1:]:

    while stack:
      prev = stack[-1]
      if flights.has_key(prev) and x in flights[prev]:
        stack.append(x)
        break
      stack.pop()

    if not stack:
      return False 
 
  return True 

def calc_zip(perm, zips):
  return [zips[i-1] for i in perm]

def calc_best_zip(N, zips, flights):
  best_zip = None
 
  for perm in itertools.permutations(range(1,N+1)):
    #print perm
    if can_solve(perm, flights):
      zip_code = calc_zip(perm, zips)
      #print zip_code
      assert zip_code != None
      if best_zip:
        if zip_code < best_zip:
           best_zip = zip_code
      else:
         best_zip = zip_code
  #print best_zip
  return "".join([str(x) for x in best_zip])

if __name__ == '__main__':
  T = int(raw_input())
  for  i in xrange(1,T+1):
    N,M = tuple(int(x) for x in raw_input().split())

    zips = []
    for j in xrange(N):
      zips.append(int(raw_input()))

    flights = {}
    for j in xrange(M):
      x,y = tuple(int(x) for x in raw_input().split())
      if flights.has_key(x):
       flights[x].append(y)
      else:
        flights[x] = [y]

      if flights.has_key(y):
        flights[y].append(x)
      else:
        flights[y] = [x]

    best_zip = calc_best_zip(N, zips, flights)

    print "Case #%s: %s" % (i, best_zip)
