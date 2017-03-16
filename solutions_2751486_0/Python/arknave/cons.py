'''
consecutive consonants in substrings.
Simple: generate all substrings, count consec, do >= statement
'''
def cons(s):
  maxx = 0
  curr = 0
  for i in range(0, len(s)):
    if not s[i] in ['a', 'e', 'i', 'o', 'u']:
      curr += 1
      maxx = max(maxx, curr)
    else:
      curr = 0
  return maxx

f = open('areal.in', 'r')
lines = f.readlines()
tt = int(lines[0])
for l in range(1, tt+1):
  thing = lines[l].split(' ')
  thing[1] = int(thing[1])
  count = 0
  for i in range(0, len(thing[0])+1):
    for j in range(i+1, len(thing[0])+1):
      if(j-i) < thing[1]:
        continue
      if cons(thing[0][i:j]) >= thing[1]:
        count+=1
  print "Case #%d: %d" % (l, count)
