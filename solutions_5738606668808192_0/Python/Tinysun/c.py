import primefac

# Small set
N=16 
J=50
jc_init = '1000000000000001'

# Large set
#N=32
#J=500
#jc_init = '10000000000000000000000000000001'

def IsPrime(n):
  return primefac.isprime(n)

def IsJamCoin(candi):
  for n in range(2, 11):
    jc_base_n = int(candi, n)
    if IsPrime(jc_base_n):
      return False
  return True

def ShowFactor(ans):
  factor_set = []
  for n in range(2, 11):
    jc_base_n = int(ans, n)
    factor = primefac.pollardRho_brent(jc_base_n)
    factor_set.append(factor)
#    factor_set.append(factor.keys()[0])
  return (True, factor_set)
  
jc_base_2 = int(jc_init, 2)

print "Case #1:"
  
found_count = 1
while True:
  jc = "{0:b}".format(jc_base_2)
  
  if IsJamCoin(jc):
#    print jc
    (success, result) = ShowFactor(jc)
    print "%s" % jc,
    for fi in result:
      print fi,
    print
    if found_count == J:
      break
    found_count = found_count+1

  jc_base_2 = jc_base_2 + 2
