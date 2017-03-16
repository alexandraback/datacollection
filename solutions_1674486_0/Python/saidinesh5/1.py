def process_input(case):
  N = len(case)
  for i in range(N):
    visited = []
    nodes = [i]
    while len(nodes) > 0:
      nodes.sort()
      node = nodes.pop()
      for item in case[node]:
        if not item in visited:
          nodes.append(item)
          visited.append(item)
        else :
          return "Yes"

  return "No"

T = int(raw_input())
for i in range(1,T+1):
  N = int(raw_input())
  testCase = []
  for j in range(N):
    testCase.append([int(n) - 1 for n in raw_input().split(' ')][1:])
  print "Case #%d: "%(i), process_input(testCase)