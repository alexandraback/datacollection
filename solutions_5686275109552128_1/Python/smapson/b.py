def iri():
  return int(raw_input())

def cuts(ham, cutsize):
  return (ham -1) / cutsize

n = iri()
for testcase in range(n):
  k = iri()
  line = [int(x) for x in raw_input().split()]
  answer = max(line)
  for eating in range(1,max(line)+1):
    dividing = sum(cuts(pancake,eating) for pancake in line)
    answer = min(answer,dividing+eating)
    if eating > answer:
      break
  print "Case #%s: %s"%(testcase+1,answer)
    
