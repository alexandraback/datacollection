N = 32
J = 500

got = 0
x = 1 << (N-1) | 1

def gen_divisors():
  yield 2
  d = 3
  for d in xrange (5, 100, 2):
    yield d
    
def is_coinjam(x):
  xs = bin(x)[2:]
  
  reprs = [(b, int(xs, b)) for b in xrange(2, 11)]
  proof = [0 for _ in xrange(0, 11)]
  #print reprs
  
  first_checking = 0
  for d in gen_divisors():      
    for r in reprs:
      if proof[r[0]] == 0 and r[1] % d == 0:
        proof[r[0]] = d
      
  proof = proof[2:]
  if min(proof) == 0:
    return False
  else:
    return proof

print 'Case #1:'
while got < J:
  proof = is_coinjam(x)
  if proof:
    print bin(x)[2:], 
    print " ".join(map(str, proof))
    got += 1
  
  x += 2
