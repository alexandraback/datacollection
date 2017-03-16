import math

def main():
	ll = []
	for i in range(10000001):
		a = i * i
		s1 = str(a)
		s2 = s1[::-1]
		if s1 == s2 and str(i) == str(i)[::-1]:
			ll.append(a)
	f = open('small.txt')
	T = int(f.readline())

	for i in range(T):
		ss = map(int, f.readline().split())
		a = ss[0]
		b = ss[1]

		res = 0
		for l in ll:
			if l >= a and l <= b:
				res += 1
		print 'Case #%d: %d' % (i + 1, res)

main()
