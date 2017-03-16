import sys

d1 = {"Z": "ZERO", "W": "TWO", "U": "FOUR", "X": "SIX", "G": "EIGHT"}
d2 = {"O":"ONE", "H": "THREE", "F":"FIVE"}
d3 = {"I": "NINE", "V": "SEVEN"}
dd = {"ZERO":0, "ONE":1, "TWO":2, "THREE":3, "FOUR":4, "FIVE":5, "SIX":6, "SEVEN":7, "EIGHT":8, "NINE":9}
def solve(s):
  r = []
  for ddict in [d1, d2, d3]:
    for key in ddict:
      while key in s:
        value = ddict[key]
        for l in value:
          s = s.replace(l, "", 1)
        r.append(dd[value])
  return "".join([str(x) for x in sorted(r)])


input_file = sys.argv[1]
with open(input_file) as f:
  T = int(f.readline().strip())
  
  for i in range(T):
    s = f.readline().strip()
    print "Case #%s: %s" % (i+1, solve(s))
