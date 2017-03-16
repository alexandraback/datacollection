INPUT_FILE = "in.txt"

def getDiff(i, origX, origY, j, origD):
  C = list(origX)
  J = list(origY)
  diff = origD
  while j < len(C):
    if diff == 0 and (C[j] == '?' or J[j] == '?'):
      dC, r = getDiff(i, C, J, j+1, 1)
      dt, r = getDiff(i, C, J, j+1, 0)
      dJ, r = getDiff(i, C, J, j+1, -1)
      m = min(dC, dt, dJ)
      if C[j] == '?' and J[j] == '?':
        if m == dt:
          C[j] = J[j] = '0'
        else:
          C[j] = '1' if m != dJ else '0'
          J[j] = '1' if m != dC else '0'
      else:
        if m == dC and (C[j] == '0' or J[j] == '9'):
          m = min(dt, dJ)
        if m == dJ and (J[j] == '0' or C[j] == '9'):
          m = min(dt, dC)

        if C[j] == '?':
          intJ = int(J[j])
          if m == dJ:
            C[j] = str(intJ - 1)
          elif m == dt:
            C[j] = J[j]
          else:
            C[j] = str(intJ + 1)
        else: # J[j] == '?'
          intC = int(C[j])
          if m == dC:
            J[j] = str(intC - 1)
          elif m == dt:
            J[j] = C[j]
          else:
            J[j] = str(intC + 1)

    elif diff > 0:
      if C[j] == '?':
        C[j] = '0'
      if J[j] == '?':
        J[j] = '9'
    elif diff < 0:
      if C[j] == '?':
        C[j] = '9'
      if J[j] == '?':
        J[j] = '0'
    diff = (diff * 10) + int(C[j]) - int(J[j])
    j += 1
  r = "case #%d: %s %s" % (i, ''.join(C), ''.join(J))
  return abs(diff), r

entries = []
with open(INPUT_FILE, 'r') as fin:
  for raw_line in fin.readlines():
    entries += [[x for x in raw_line.split()]]
T = int(entries[0][0])

for i in xrange(1, T+1):
  C = list(entries[i][0])
  J = list(entries[i][1])
  diff, r = getDiff(i, C, J, 0, 0)
  print r
