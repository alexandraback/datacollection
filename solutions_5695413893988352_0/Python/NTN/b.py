def aa(ip):
	if ip.find("?") != -1:
		return 2395789
	a, b = map(int, ip.split())
	return abs(a - b)

def r(ip):
	global best
	if ip.find("?") == -1:
		if aa(best) == aa(ip):
			a, b = map(int, ip.split())
			a2, b2 = map(int, best.split())
			if a < a2:
				best = ip
			elif a == a2 and b < b2:
				best = ip
		elif aa(best) > aa(ip):
			best = ip
		return

	for i in range(10):
		r(ip.replace("?", str(i), 1))

n = int(input())

for i in range(n):
	ip = input()
	if ip == "??? ???":
		best = "000 000"
	else:
		best = ip
		r(ip)
	print("Case #%s:" % str(i+1), best)