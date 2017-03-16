import sys

r = {}

def add(s, l):
  if "?" in s:
    for i in range(len(s1)):
      if s[i] == "?":
        for j in range(10):
          sj = s.replace("?", str(j), 1)
          add(sj, l)
  else:
    l.append(s)

def solve(s1, s2):
  a= []
  b= []
  add(s1, a)
  add(s2, b)
  for aa in a:
    for bb in b:
      dif= max((int(aa), int(bb))) - min((int(aa), int(bb)))
      if dif not in r:
        r[dif] = []
      r[dif].append((aa,bb))
      if dif == 0:
        return





input_file = sys.argv[1]
with open(input_file) as f:
  T = int(f.readline().strip())
  
  for i in range(T):
    s1, s2 = f.readline().strip().split(" ")
    solve(s1, s2)
    solution = sorted(r[min(r.keys())])[0]
    print "Case #%s: %s %s" % (i+1, solution[0], solution[1])
    r = {}
    a = []
    b = []
