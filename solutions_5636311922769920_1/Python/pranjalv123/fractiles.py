def fractiles(k, c, s):
    if c*s < k:
        return "IMPOSSIBLE"


    groups = [[]]
    for i in range(k):
        if len(groups[-1]) == c:
            groups.append([])
        groups[-1].append(i)

    indices = []
    for group in groups:
        current = 0
        level = 0
        for char in group:
            current += char * k**level
            level += 1
        indices.append(current)
        assert(current <= 10**18)
    
    return " ".join([str(i+1) for i in indices])


t = int(raw_input())  # read a line with a single integer

for n in xrange(1, t + 1):
  k, c, s = tuple([int(i) for i in raw_input().split(" ")])
  print "Case #{}: {}".format(n, fractiles(k,c,s))
