
import sys

# build list of all combos within 2 of eachother
combos = [(i,j,k) for i in range(11) for j in range(i,11) for k in range(j,11) if abs(i-j) < 3 and abs(i-k) < 3 and abs(j-k) < 3]
totals = dict()

# build metadata for combos (max and supprise)
for c in combos:
  t = sum(c)

  v = (
    c,
    abs(c[0]-c[1]) == 2 or abs(c[0]-c[2]) == 2 or abs(c[1]-c[2]) == 2,
    max(c)
  )

  if t in totals:
    totals[t].append(v)
  else:
    totals[t] = [ v ]

count = int(sys.stdin.readline())

for i in range(count):
  parts = sys.stdin.readline().split(' ')

  N = int(parts[0]) # number of googlers
  S = int(parts[1]) # number of suprising
  p = int(parts[2]) # min best value
  t = [int(j) for j in parts[3:N+3]] # googler total points

  val = 0

  for tot in t:
    # Get options matching min best
    opts = [opt for opt in totals[tot] if opt[2] >= p]

    # inc val for any matching non-suprise option
    if any(not o[1] for o in opts):
      val += 1

    # and inc for suprise if suprise count still > 0
    elif len(opts) > 0 and S > 0:
      val += 1
      S -= 1

  print "Case #%d: %s" % (i+1, val)

