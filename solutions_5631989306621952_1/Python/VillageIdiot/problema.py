import sys
def doTest(s):
  out = ""
  for c in s:
    if len(out) > 0:
      if ord(c) >= ord(out[0]):
        out = c + out
      else:
        out = out + c
    else:
      out = c
  return out.rstrip('\n')

inlines = open(sys.argv[1]).readlines()
numcases = int(inlines[0])
idx = 1

for case in range(numcases):
    print "Case #%d: %s" % (case + 1, doTest(inlines[idx] ))
    idx += 1


