def follow_tile(K, C, lst):
  pos = 0
  for p in xrange(C):
    if p < len(lst):
      pos = pos * K + lst[p]
    else:
      pos = pos * K
  return pos + 1
  
def do_case(K,C,S):
  if S*C < K:
    return "IMPOSSIBLE"
  out = list()
  for i in range(0, K, C):
    out.append(follow_tile(K, C, range(i,min(i+C,K))))
  sd = [str(c) for c in out]
  return " ".join(sd)
 
f = open("D-small-attempt1.in").read()
lines = f.split("\n")
T = int(lines[0])
i=1
out=""
for line in lines[1:]:
  if len(line) > 0:
    parts = line.split(" ")
    out+="Case #%d: %s\n" % (i, do_case(int(parts[0]),int(parts[1]),int(parts[2])))
    i+=1
  
open("D-small.out","w").write(out)