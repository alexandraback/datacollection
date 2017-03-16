import sys
import itertools
import math

# OKAY I BARELY TRIED TO THINK AT ALL

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

  if not all(map(isvalid, strs)):
    return 0

  #print strs

  strs = sorted(map(preproc, strs))

  # fuck off
  for st in range(len(strs)):
    for c in strs[st][1:-1]:
      for st2 in range(len(strs)):
        if st2 != st and c in strs[st2]:
          return 0

  strs = map(lambda x: x[0] + x[-1], strs)

  # fuck off also
  for st in range(len(strs)):
    for st2 in range(len(strs)):
      if st2 != st and strs[st] == strs[st2] and strs[st][0] != strs[st][1]:
        return 0


  ret = 1



  # put the shits together that we have to
  anygood = 1
  while anygood:
    #print strs

    # find all dup shits and mult the fact shit it's late
    # lates LIKE 3:47 AM GOTTA SLEEEEEP
    done = []
    for c in strs:
      if c[0] == c[1]:
        if c not in done:
          done.append(c)
          cnt = 0   # ewww
          for l in strs:
            if l == c:
              cnt += 1

          #print c, cnt
          ret *= math.factorial(cnt)
      else:
        done.append(c)
    strs = done

    # hack out the dups
    done = []
    for c in strs:
      if c[0] == c[1]:
        die = 0
        for l in strs:
          if l != c and (l[0] == c[1] or l[1] == c[0]):
            die = 1
            break
        if die == 0:
          done.append(c)
      else:
        done.append(c)
    strs = done


    #print strs

    anygood = 0
    done = []
    for c in range(len(strs)):
      matchees = []
      for l in range(len(strs)):
        if c != l and strs[c][1] == strs[l][0]:
          matchees.append(l)
      if len(matchees) > 1:
        #print "BAD BAD BAD", matchees
        # you broke shit
        return 0
      elif len(matchees) == 1:
        anygood = 1
        l = matchees[0]
        me = [strs[c][0] + strs[l][1]]
        if me[0][0] == me[0][1]:
          # BAD MERGE
          return 0
        #print "merging", strs[c], strs[l], me
        if l < c:
          t = c
          c = l
          l = t
        strs = strs[0:c] + strs[c+1:l] + strs[l+1:] + me
        anygood = 1
        break

  #print strs



  """
  fret = 0
  for arr in itertools.permutations(strs):
    fret += isvalid(''.join(arr))
  ret *= fret
  """
  ret *= math.factorial(len(strs))

  return ret
  

bigmod = 1000000007
dat = open(sys.argv[1]).read().split("\n")
for case in range(int(dat[0])):
  strcount = int(dat[1+case*2])
  strs = dat[2+case*2].split(" ")
  print "Case #"+str(case+1)+":",runcase(strs)%bigmod
  


