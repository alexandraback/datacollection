import sys, StringIO

def generate(a):
  r = []
  f = "%0" + str(a.count('?')) + "d"

  for n in range(10**a.count('?')):
    s = a
    for x in str(f % n):
      s = s.replace('?', x, 1)
    r.append(int(s, 10))
  return r

def sortDups(a, b):
  if (a[0] == b[0]):
    return a[1]-b[1]
  return a[0]-b[0]

def solution(a, b):
  ga = sorted(generate(a))
  gb = sorted(generate(b))

  #print a,b
  #print ga,gb
  ia = 0
  ib = 0
  m = abs(ga[0]-gb[0])
  d = [(ga[0],gb[0])]
  while ia!=len(ga)-1 or ib!=len(gb)-1:
    #print "start loop", ia, ib
    if ia==len(ga)-1:
      ib += 1
    else:
      if ib==len(gb)-1:
        ia += 1
      else:
        if ga[ia]<gb[ib]:
          ia += 1
        else:
          ib += 1
    if abs(ga[ia]-gb[ib])==m:
      d.append((ga[ia], gb[ib]))
      #print m, d
    if abs(ga[ia]-gb[ib])<m:
      m = abs(ga[ia]-gb[ib])
      d = [(ga[ia], gb[ib])]
      #print m, d

  d.sort(sortDups)
  #print d
  m = d[0]

  f = "%0" + str(len(a)) + "d %0" + str(len(a)) + "d"
  return f % (m[0], m[1])
#solution


if __name__ == '__main__':
  if len(sys.argv)>1:
    input = file(sys.argv[1])
  else:
    input = StringIO.StringIO("""4
?1 ?2
?25 ?34
? ?
?5 ?0""")
  cases = int(input.readline())
  for case in range(cases):
    a, b = input.readline().strip().split()
    print("Case #%d: %s" % (case+1, solution(a,b)))
