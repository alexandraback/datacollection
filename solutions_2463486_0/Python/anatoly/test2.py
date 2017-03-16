import sys

def gen_pali(pwr):
	n = int(pwr / 2)
	if n == 0:
		for x in range(1, 10):
			yield x
	else:
		for i in range(10 ** (n-1), 10 ** n):
			s1 = str(i)
			s2 = s1[::-1]
			if pwr % 2:
				for d in range(0, 10):
					yield s1 + str(d) + s2
			else:
				yield s1 + s2

def is_pali(x):
  s = str(x)
  l = len(s)

  for i in range(0, int(l / 2) + 1):
    if s[i] != s[l - i - 1]:
      return False
  return True

fairsq = []	
for pwr in range(1, 10):
	palisq = (int(x)*int(x) for x in gen_pali(pwr))
#	print(pwr-1, [x for x in palisq if is_pali(x)])
	fairsq.extend((x for x in palisq if is_pali(x)))

T = int(sys.stdin.readline())
for tc in range(0, T):
	A, B = map(int, sys.stdin.readline().split())
	print("Case #%d: %d" % (tc + 1, sum(1 for _ in (x for x in fairsq if x >= A and x <= B))))