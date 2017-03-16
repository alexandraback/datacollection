from subprocess import Popen, PIPE

def factor(n):
  process = Popen(["factor", str(n)], stdout=PIPE)
  (output, err) = process.communicate()
  process.wait()
  output = output[len(str(n))+2:]
  output = output.rstrip()
  output = output.split(' ')
  if (len(output) == 1):
    return -1
  else:
    return int(output[0])

def convert(n):
  base2 = bin(n)[2:]
  ret = [n]
  for b in xrange(3, 11):
    accum = 0
    for i in base2:
      accum = accum * b + ord(i) - ord('0')
    ret.append(accum)
  return ret

def test(n):
  bs = convert(n)
  bs = map(factor, bs)
  if (-1) in bs:
    return None
  return bs

n = 2**15+1
ret = []
want = 50
while (len(ret) < want):
  fs = test(n)
  if fs:
    ret.append((n, fs))
  n += 2

print "Case #1:"
for n, fs in  ret:
  print bin(n)[2:], 
  for f in fs:
    print f,
  print ""
