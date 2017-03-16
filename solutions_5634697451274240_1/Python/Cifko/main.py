filename = "B-large.in"
outf = open("/storage/emulated/0/Download/B.out", "wt")
f = open("/storage/emulated/0/Download/" + filename, "rt")

def solve(s):
  if not s or s.count("-")==0:
    return 0
  f=0
  l=0
  i=0
  b=1
  for c in s:
    if b and c=="+":
      f += 1
    else:
      b=0
    if c=="-":
      l=i
    i+=1
  R = 0
  if f>0:
    r=""
    for c in s[:f][::-1]:
      r += "+-" [c=="+"]
    r += s[f:]
    R += 1
    s=r
  r=""
  for c in s[:l+1][::-1]:
    r += "+-" [c=="+"]
  r += s[l+1:]
  R += 1
  s=r
  return R + solve(r)

def out(x):
  print x
  outf.write(x+"\n")
  
T = int(f.readline())
for t in range(1, T+1):
    out("Case #%d: %s" %(t,solve(f.readline())))