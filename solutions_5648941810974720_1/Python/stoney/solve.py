INPUT_FILE = "A-large.in" #"in.txt"

t = ["ZERO",
     "ONE",
     "TWO",
     "THREE",
     "FOUR",
     "FIVE",
     "SIX",
     "SEVEN",
     "EIGHT",
     "NINE"]

def add(num, S, digit):
  num += [digit]
  for ch in t[digit]:
    S[ch] -= 1
    if S[ch] == 0:
      del S[ch]

entries = []
with open(INPUT_FILE, 'r') as fin:
  for raw_line in fin.readlines():
    entries += [[x for x in raw_line.split()]]
T = int(entries[0][0])

for i in xrange(1, T+1):
  S = dict()
  for c in list(entries[i][0]):
    if c not in S:
      S[c] = 1
    else:
      S[c] += 1
  num = []
  while 'Z' in S:
    add(num, S, 0)
  while 'W' in S:
    add(num, S, 2)
  while 'X' in S:
    add(num, S, 6)
  while 'G' in S:
    add(num, S, 8)
  while 'S' in S:
    add(num, S, 7)
  while 'V' in S:
    add(num, S, 5)
  while 'I' in S:
    add(num, S, 9)
  while 'U' in S:
    add(num, S, 4)
  while 'H' in S:
    add(num, S, 3)
  while 'O' in S:
    add(num, S, 1)
  print "case #%d: %s" % (i, ''.join(str(x) for x in sorted(num)))
