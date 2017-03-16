import sys

def solve(l):
  j = l[0]
  p = l[1]
  s = l[2]
  k = l[3]
  
  seen_a = {}
  seen_b = {}
  seen_c = {}
  all_pairs = set()
  outfits = []
  index1 = 1
  index2 = 2
  for i3 in range(1, s+1):
    for i1 in range(1, j+1):
      for i2 in range(1, p+1):
        add = True
        v1 = (index1 % j) +1
        v2 = (index2 % p)+1
        cur = (v1, v2, i3)
        pair_a = (v1, i3)
        pair_b = (v2, i3)
        pair_c = (v1, v2)
        if pair_a not in seen_a: seen_a[pair_a] = 0
        if seen_a[pair_a] >= k:
          add = False
        if pair_b not in seen_b: seen_b[pair_b] = 0
        if seen_b[pair_b] >= k:
          add = False
        if pair_c not in seen_c: seen_c[pair_c] = 0
        if seen_c[pair_c] >= k:
          add = False
        if add:
          seen_a[pair_a] = seen_a[pair_a] + 1
          seen_b[pair_b] = seen_b[pair_b] + 1
          seen_c[pair_c] = seen_c[pair_c] + 1
          outfits.append(" ".join( [str(x) for x in cur] ))
        index1+=1
        index2+=1
  
  return (len(outfits), outfits)


input_file = sys.argv[1]
with open(input_file) as f:
  T = int(f.readline().strip())
  
  for i in range(T):
    l = [int(x) for x in f.readline().strip().split(" ")]
    result = solve(l)
    print "Case #%s: %s" % (i+1, result[0])
    for r in result[1]:
      print r
