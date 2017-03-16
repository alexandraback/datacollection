import sys
import string

numcases = int(sys.stdin.readline())
for casenum in xrange(1,numcases+1):
  max_str, aud_str = string.split(sys.stdin.readline().strip())
  max_val = int(max_str)
  aud = [int(s) for s in aud_str]
  assert max_val + 1 == len(aud)

  res = 0
  pref_sum = 0
  for i, cnt in enumerate(aud):
    if cnt == 0:
      continue

    to_add = i - (pref_sum + res)
    if to_add > 0:
      res = res + to_add
    pref_sum = pref_sum + cnt
 
  print 'Case #' + repr(casenum) + ': ' + str(res)
