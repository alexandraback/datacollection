
f = open( "1", "r" )
l = f.readlines()

tests = int(l[0])
current = 1

for tc in xrange(1, tests+1):
  line = l[current].strip()
  current += 1
  (a, b) = line.split( " " )
  a = int(a)
  b = int(b)
  r = b - a
  line = l[current].strip()
  current += 1
  ps = line.split( " " )
  for i in xrange(0,len(ps)):
    ps[i] = float(ps[i])
  p_ok = 1.0

  for p in ps:
    p_ok = p_ok * p

  #print "p_ok", p_ok

  # best strategy
  s_c = ( r + 1 ) * p_ok + ( r + 1 + b + 1 ) * ( 1 - p_ok ) # continue
  s_r = 1 + ( b + 1 ) # restart

  #print "s_c:", s_c
  #print "s_r:", s_r

  best = min( s_c, s_r )

  for bs in xrange( 1, a+1 ):
    ok_up_to_bs = 1
    for rem in xrange( 0, a - bs ):
      ok_up_to_bs = ok_up_to_bs * ps[rem]
    cost = ok_up_to_bs * ( bs + bs + r + 1 ) + ( 1 - ok_up_to_bs ) * ( bs + bs + r + 1 + b + 1 )
    #print "cost for", bs, ":", cost
    if cost < best:
      best = cost

  print "Case #%i: %.6f" % ( tc, best )
