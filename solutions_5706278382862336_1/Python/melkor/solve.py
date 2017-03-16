
INF = 9999999999

def normalize_frac(P,Q):
  for i in xrange(40,1,-1):
   if Q < (2**i):
     continue
   if Q % (2**i) == 0:
     ratio = Q / (2**i)
     if P % ratio == 0:
       return P/ratio, Q/ratio

  return P,Q

def num_generations(P,Q):
 
  if P > Q:
    return INF

  P,Q = normalize_frac(P,Q)
  if not is_pow_of_2(Q):
    return INF

  if Q > 2**40:
    return INF

  ratio = 2**40 / Q
 
  P_norm = P * ratio

  for i in xrange(1,40):
    if P_norm >= (2**(40-i)):
      return i

  return INF
 

def is_pow_of_2(x):
  return x & (x-1) == 0

if __name__ == '__main__':
  T = int(raw_input())
  for i in xrange(1,T+1):
    P,Q = tuple(int(x.strip()) for x in raw_input().split("/"))
    res = num_generations(P,Q)
    if res == INF:
      print "Case #%s: impossible" % i
    else:
      print "Case #%s: %s" % (i,res)
    
