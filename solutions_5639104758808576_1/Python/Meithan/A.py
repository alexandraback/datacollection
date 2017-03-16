import sys


def solve(Smax, persons):
  if int(persons[0]) == 0:
    friends = 1
    total = 1
  else:
    friends = 0
    total = int(persons[0])
  for k in range(1,Smax+1):
    if total < k:
      friends += (k-total)
      total += int(persons[k]) + (k-total)
    else:
      total += int(persons[k])
  return friends


f = open(sys.argv[1],"r")
T = int(f.readline())
for case in range(1,T+1):
  rawdata = f.readline().strip("\n").split()
  Smax = int(rawdata[0])
  persons = rawdata[1]
  friends = solve(Smax, persons)
  print "Case #%i: %i" % (case, friends)

