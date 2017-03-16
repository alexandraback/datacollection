from codejam import CodeJam, parsers

def solve(line):
  j = int(line[0])
  p = int(line[1])
  s = int(line[2])
  k = int(line[3])

  max1 = j*p*s
  #print("max1:" + str(max1))
  max2 = j*p*k
  #print("max2:" + str(max2))
  realMax = min(max1, max2)

  output = str(realMax) + "\n"

  cj = 0
  cp = 0
  cs = 0
  ck = 0
  if k < s:
    dj = {}
    dp = {}
    djp = {}
    overall = {}
    output = ""
    counter = 0
    for i in range(0, realMax):
      counter += 1
      output += "%d %d %d\n" % (cj + 1, cp + 1, cs + 1)
      overall[(cj, cp, cs)] = 1
      djp[(cj, cp)] = djp.get((cj, cp), 0) + 1
      dj[(cj, cs)] = dj.get((cj, cs), 0) + 1
      dp[(cp, cs)] = dp.get((cp, cs), 0) + 1
      ck += 1

      cj = 0
      cp = 0
      cs = 0

      found = False
      while not found and cj < j and cp < p:
        if djp.get((cj, cp), 0) < k:
          for a in range(0, s):
            if dj.get((cj, a), 0) < k and dp.get((cp, a), 0) < k and not (cj, cp, a) in overall:
              # print(dj)
              # print(dp)
              # print("dj(%d,%d) = %d" % (cj, a, dj.get((cj, a), 0)))
              # print("dp(%d,%d) = %d" % (cp, a, dp.get((cp, a), 0)))
              # print("Found: %d,%d -> %d" % (cj, cp, a))
              cs = a
              found = True
              break
        if not found:
          cs += 1
          if cs >= s:
            cs = 0
            cp += 1
            if cp >= p:
              cp = 0
              cj += 1
      if not found:
        # print("Not found (%d,%d)" % (cj, cp))
        # print(dj)
        # print(dp)

        return str(counter) + "\n" + output
    #print(dj)
    #print(dp)
    return str(counter) + "\n" + output

  for i in range(0, realMax):
    output += "%d %d %d\n" % (cj + 1, cp + 1, cs + 1)
    cs += 1
    if cs >= s:
      cs = 0
      cp += 1
      if cp >= p:
        cp = 0
        cj = (cj + 1) % j

  return output

if __name__ == "__main__":
  CodeJam(parsers.ints, solve).main()
