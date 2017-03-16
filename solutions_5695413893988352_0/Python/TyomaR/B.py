def solve1(a, b):
	x, y = "", ""
	n = len(a)
	less = 0
	for i in range(n):
		if less == 0:
			if a[i] == '?' and b[i] == '?':
				x += '0'
				y += '0'
			elif a[i] == '?':
				x += b[i]
				y += b[i]
			elif b[i] == '?':
				x += a[i]
				y += a[i]
			else:
				if a[i] < b[i]:
					less = -1
				elif a[i] == b[i]:
					pass
				else:
					less = 1
				x += a[i]
				y += b[i]
		elif less == -1:
			if a[i] == '?' and b[i] == '?':
				x += '9'
				y += '0'
			elif a[i] == '?':
				x += '9'
				y += b[i]
			elif b[i] == '?':
				x += a[i]
				y += '0'
			else:
				x += a[i]
				y += b[i]
		else:
			if a[i] == '?' and b[i] == '?':
				x += '0'
				y += '9'
			elif a[i] == '?':
				x += '0'
				y += b[i]
			elif b[i] == '?':
				x += a[i]
				y += '9'
			else:
				x += a[i]
				y += b[i]			
	return (x, y)

def solve2(a, b):
	n = len(a)
	ans = 10000000000000
	x = ''
	y = ''
	for i in range(10 ** n):
		for j in range(max(0, i - ans), min(10 ** n, i + ans)):
			q = str(i)
			w = str(j)
			q = '0' * (n - len(q)) + q
			w = '0' * (n - len(w)) + w
			bad = False
			for k in range(n):
				if a[k] != '?' and a[k] != q[k]:
					bad = True
					break
			if bad: 
				continue
			for k in range(n):
				if b[k] != '?' and b[k] != w[k]:
					bad = True
					break
			if bad: 
				continue
			pot = abs(i - j)
			if ans > pot:
				ans = pot
				x = q
				y = w
	return (x, y)
def main():
	for case in range(1, int(input()) + 1):
		a, b = input().split()
		x, y = solve2(a, b)
		print("Case #%d: %s %s" % (case, x, y))
if __name__ == '__main__':
	main()