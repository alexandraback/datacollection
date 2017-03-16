def solve(input_file):
  f = open(input_file, 'r')
  output_file = input_file.split('.')[0] + ".out"
  o = open(output_file, 'w')
  num_tests = int(f.readline())
  for nt in range(num_tests):
    N = int(f.readline().strip())
    BFF = map(int, f.readline().split(' '))
    print "Doing case %d: " % (nt+1)
    print BFF
    visited = range(1,N+1)
    chains = dict()
    while True:
      if len(visited) > 0:
        # print chains
        start = visited[0]
        visited.remove(start)
        next = get(BFF, start)
        currentlyVisited = [start]
        broken = False
        while next not in currentlyVisited:
          # print "begin"
          # print visited
          # print currentlyVisited
          # print next
          # print "end"
          if next in chains:
            broken = True
            if chains[next][1]:
              chains[start] = (0, True)
            else:
              chains[start] = (chains[next][0] + 1, False, chains[next][2], chains[next][3])
            break
          currentlyVisited.append(next)
          if next in visited:
            visited.remove(next)
          next = get(BFF, next)
        # print "evaluating"
        # print start, next
        # print currentlyVisited
        if not broken:
          if start == next:
            for i in range(len(currentlyVisited)):
              chains[currentlyVisited[i]] = (len(currentlyVisited), True)
          else:
            index = currentlyVisited.index(next)
            if index == len(currentlyVisited) - 2:
              chains[start] = (len(currentlyVisited), False, currentlyVisited[index], currentlyVisited[index + 1])
            else:
              for i in range(0, index):
                chains[currentlyVisited[i]] = (0, True)
              for i in range(index, len(currentlyVisited)):
                chains[currentlyVisited[i]] = (len(currentlyVisited) - index, True)
      else:
        break
    longestTrue = 0
    sumFalses = 0
    numHooks = 0
    sorted_chains = sorted(chains.values(), key=lambda x: -x[0])
    print sorted_chains
    sawHook = set()
    for val in sorted_chains:
      if val[1] == True and longestTrue == 0:
        longestTrue = val[0]
      if val[1] == False and (val[2], val[3]) not in sawHook:
        if (val[3], val[2]) not in sawHook:
          sumFalses += val[0]
          numHooks += 1
        else:
          sumFalses += val[0] - 2
        sawHook.add((val[2], val[3]))
    print longestTrue
    print sumFalses
    print numHooks
    ans = -1
    if longestTrue + numHooks * 2 > sumFalses:
      ans = longestTrue + numHooks * 2
    else:
      ans = sumFalses

    o.write("Case #%d: %d\n" % ((nt+1), ans))

def get(BFF, index):
  return BFF[index - 1]

solve('C-small-attempt0.in')
