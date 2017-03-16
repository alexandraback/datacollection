# 10:12

MAX = 2**17
N = 32
J = 500

# MAX = 2**9
# N = 16
# J = 50

vis = [0]*MAX
# not_prime = [i for i in range(2, MAX) for j in range(2, int(i**0.5)+1) if i%j==0]
# prime = [i for i in range(2, MAX) if i not in not_prime]
prime = []
for i in range(2, MAX):
  if not vis[i]:
    prime.append(i)
    for j in range(2*i, MAX, i):
      vis[j]=1
primeset = set(prime)

# def test(s):
#   for base in range(2, 11):
#     n = int(s, base)
#     if n in primeset:
#       return False
#   else: return True

def give(s):
  ret = []
  for base in range(2, 11):
    n = int(s, base)
    for p in prime:
      if p > int(n**0.5)+2: break
      if n%p == 0:
        ret.append(p)
        break
  return ret if len(ret)==9 else None

def build_(n):
  count = 0
  ans = []
  # for i in xrange(2**(n-1)+1, 2**n, 2):
  i = 2**(n-1)+1
  while i < 2**n:
    s = bin(i)[2:]
    tmp = give(s)
    if tmp:
      ans.append((s, tmp))
      count += 1
      if count >= J: break
    i+=2
  return ans

ans = build_(N)
print "finish build"

f = open("C-large.out", "w")
f.write("Case #1:\n")
for j in xrange(J):
  f.write("{} ".format(ans[j][0]))
  for k in ans[j][1]:
    f.write("{} ".format(k))
  f.write("\n")
f.close()