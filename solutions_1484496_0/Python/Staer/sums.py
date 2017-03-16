def find_combos(initial_set):
  from itertools import combinations
  for size in xrange(1,num_elements):
    for combo1 in combinations(initial_set, size):
      for size2 in xrange(1, num_elements):
        for combo2 in combinations(initial_set, size2):
          if combo1 != combo2 and sum(combo1)==sum(combo2):
            return [combo1, combo2]
  return None

if __name__ == "__main__":
  import sys
  f = sys.stdin
  T = int(f.readline())

  for i in xrange(T):
    data = f.readline().strip().split(' ')
    num_elements = int(data[0])
    initial_set = []
    for d in xrange(num_elements):
      initial_set.append(int(data[d+1]))

    print "Case #%s:" % (i+1)
    result = find_combos(initial_set)   
    if result == None:
      print "Impossible"
      continue
    else:
      for combo in result:
        # Print the combo on a line    
        as_strings = []
        for item in combo:
          as_strings.append(str(item))
        print ' '.join(as_strings)

