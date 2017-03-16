import sys
import itertools

def runcase(strs):
  def preproc(s):
    ret = s[0]
    for i in range(1, len(s)):
      if ret[-1] != s[i]:
        ret += s[i]
    return ret

  def isvalid(s):
    for i in range(1, len(s)):
      if s[i] in s[0:i-1] and s[i] != s[i-1]:
        return False
    return True

  ret = 0
  #print strs, map(preproc, strs)
  for arr in itertools.permutations(map(preproc, strs)):
    ret += isvalid(''.join(arr))

  return ret
  

bigmod = 1000000007
dat = open(sys.argv[1]).read().split("\n")
for case in range(int(dat[0])):
  strcount = int(dat[1+case*2])
  strs = dat[2+case*2].split(" ")
  print "Case #"+str(case+1)+":",runcase(strs)
  


