from collections import defaultdict
def minus_all(dict, str):
  for ch in str:
    dict[ch]-=1

def do_case(strs):
  dict = defaultdict(int)
  for ch in strs:
    dict[ch]+=1
  outdigits = list()
  while dict['Z'] > 0:
    minus_all(dict,'ZERO')
    outdigits.append(0)
  while dict['X'] > 0:
    minus_all(dict,'SIX')
    outdigits.append(6)
  while dict['G'] > 0:
    minus_all(dict,'EIGHT')
    outdigits.append(8)
  while dict['H'] > 0:
    minus_all(dict,'THREE')
    outdigits.append(3)
  while dict['R'] > 0:
    minus_all(dict,'FOUR')
    outdigits.append(4)
  while dict['F'] > 0:
    minus_all(dict,'FIVE')
    outdigits.append(5)
  while dict['V'] > 0:
    minus_all(dict,'SEVEN')
    outdigits.append(7)  
  while dict['W'] > 0:
    minus_all(dict,'TWO')
    outdigits.append(2)  
  while dict['O'] > 0:
    minus_all(dict,'ONE')
    outdigits.append(1) 
  while dict['I'] > 0:
    minus_all(dict,'NINE')
    outdigits.append(9)
  outdigits.sort()
  out = [str(d) for d in outdigits]
  outs = ""
  for ch in out:
    outs+=ch
  return outs
    
f = open("Round1B/A-small-attempt0.in").read()
lines = f.split("\n")
T = int(lines[0])
i=1
out=""
for line in lines[1:]:
  if len(line) > 0:
    parts = line.split(" ")
    out+="Case #%d: %s\n" % (i, do_case(parts[0]))
    i+=1
  
open("Round1B/A-small.out","w").write(out)
