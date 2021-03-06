import sys

products = {"11":"+1", "1i":"+i", "1j":"+j", "1k":"+k",
            "i1":"+i", "ii":"-1", "ij":"+k", "ik":"-j",
            "j1":"+j", "ji":"-k", "jj":"-1", "jk":"+i",
            "k1":"+k", "ki":"+j", "kj":"-i", "kk":"-1"}
def quat_mult(a,b):
  sa = 1.0 if a[0]=="+" else -1.0
  sb = 1.0 if b[0]=="+" else -1.0
  p = products[a[1]+b[1]]
  sp = 1.0 if p[0]=="+" else -1.0
  if sa*sb*sp < 0: p = "-" + p[1]
  else: p = "+" + p[1]
  return p
  
def quat_reduce(quat):
  if len(quat) <= 1: return "+" + quat
  p = "+" + quat[0]
  for i in range(1,len(quat)):
    p = quat_mult(p,"+"+quat[i])
  return p

def quat_power(quat,n):
  if quat == "+1": return "+1"
  if quat == "-1": return ("+" if n%2 == 0 else "-") + "1"
  s = 1.0 if quat[0] == "+" else -1.0
  q = quat[1]
  if n%4 == 1:
    sf = s**n
    qf = q
  elif n%4 == 2:
    sf = (-1)*s**n
    qf = "1"
  elif n%4 == 3:
    sf = (-1)*s**n
    qf = q
  elif n%4 == 0:
    sf = s**n
    qf = "1"
  sf = "+" if sf > 0 else "-"
  return sf + qf

f = open(sys.argv[1],"r")
T = int(f.readline())
for case in range(1,T+1):
  L, X = map(int, f.readline().split())
  if L*X < 3:
    quatstr = f.readline()
    print "Case #%i: NO" % (case)
  else:
    quatstr = f.readline().strip()
    if quat_power(quat_reduce(quatstr), X) == "-1":
    
      quatstr = quatstr*X
      found_i = False
      for i in range(len(quatstr)-2):
        if quat_reduce(quatstr[:i+1]) == "+i":
          imax = i
          found_i = True
          break
      if not found_i: print "Case #%i: NO" % (case)
      else:
        found_k = False
        for i in range(len(quatstr)-imax-1):
          if quat_reduce(quatstr[len(quatstr)-1-i:]) == "+k":
            found_k = True
            break
        if not found_k: print "Case #%i: NO" % (case)
        else: print "Case #%i: YES" % (case)
      
    else:
      print "Case #%i: NO" % (case)      
    
  
    
