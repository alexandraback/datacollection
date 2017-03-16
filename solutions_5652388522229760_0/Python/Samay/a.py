req_list = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
current_list = []

def splitnumber(n):
  list_of_ints = [int(i) for i in str(n)]
  list_of_ints = list(set(list_of_ints))
  return list(set(list_of_ints))

t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
  n = int(raw_input())
  if n == 0:
    print "Case #{}: INSOMNIA".format(i)
  else:
    del current_list[:]
    for j in range(1,200):
      current_list = current_list + splitnumber(n * j)
      current_list = list(set(current_list))
      if cmp(current_list, req_list) == 0:
        print "Case #{}: {}".format(i, n * j)
        break
  # check out .format's specification for more formatting options
