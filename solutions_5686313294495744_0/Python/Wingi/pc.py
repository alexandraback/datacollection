import sys, StringIO



def solution(w):
  sa = set()
  sb = set()
  c = 0
  for a, b in w:
    if a not in sb and a in sa and b not in sa and b in sb:
      c += 1
    sa.add(a)
    sb.add(b)
  return c
#solution


if __name__ == '__main__':
  if len(sys.argv)>1:
    input = file(sys.argv[1])
  else:
    input = StringIO.StringIO("""3
3
HYDROCARBON COMBUSTION
QUAIL BEHAVIOR
QUAIL COMBUSTION
3
CODE JAM
SPACE JAM
PEARL JAM
2
INTERGALACTIC PLANETARY
PLANETARY INTERGALACTIC""")
  cases = int(input.readline())
  for case in range(cases):
    c = int(input.readline().strip())
    w = []
    for x in range(c):
      w.append(input.readline().strip().split())
    print("Case #%d: %d" % (case+1, solution(w)))
