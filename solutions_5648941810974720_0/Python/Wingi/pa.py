import sys, StringIO

def replaceAll(s, r):
  for x in r:
    s = s.replace(x, ' ', 1)
  return s

def solution(s):
  r = []
  #find "THREE",  "NINE"
  for i, n in [(8, 'GEIHT'), (6, 'XSI'), (0, 'ZERO'), (4,'UFOR'), (7, 'SEVEN'),
               (5, 'VFIE'), (2, 'WTO'), (1, 'ONE'), (3, 'THREE'), (9, 'NINE')]:
    while s.find(n[0])>-1:
      r.append(i)
      s = replaceAll(s, n)

  return ''.join([str(x) for x in sorted(r)])
#solution


if __name__ == '__main__':
  if len(sys.argv)>1:
    input = file(sys.argv[1])
  else:
    input = StringIO.StringIO("""4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER""")
  cases = int(input.readline())
  for case in range(cases):
    s = input.readline().strip()
    print("Case #%d: %s" % (case+1, solution(s)))
