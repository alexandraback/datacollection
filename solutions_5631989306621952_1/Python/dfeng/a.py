# fname = "A-small-attempt1.in.txt"
fname = "A-large.in.txt"
# fname = "test.in"

def to_num(s):
  return ord(s.lower()) - 96

def to_str(s):
  return chr(s + ord('A') - 1)


def solve(s):
  s = map(to_num, s)
  # print s
  ret = []
  end = []
  while len(s) > 0:
    m = max(s)
    maxs = [i for i, j in enumerate(s) if j == m]
    for mx in maxs[::-1]:
      # print mx
      end = s[mx+1:] + end
      s = s[:(mx+1)]
      ret.append(s[mx])
      del s[mx]
      
  return "".join(map(to_str, ret + end))

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      s = list(f.readline().split()[0])
      print 'Case #%s: %s' % (i + 1, solve(s))

main()