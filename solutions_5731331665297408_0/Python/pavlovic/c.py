import sys
import itertools

t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",

	n, m = [int(j) for j in sys.stdin.readline().strip().split()]
	
	zip_codes = []
	flights = []
	for j in range(n):
		f = []
		for k in range(n):
			f.append(False)
		flights.append(f)
	
	for j in range(n):
		s = sys.stdin.readline().strip()
		zip_codes.append(s)
	for j in range(m):
		p, q = [int(j) for j in sys.stdin.readline().strip().split()]
		flights[p - 1][q - 1] = True
		flights[q - 1][p - 1] = True

	lowest_zip = ""
	
	for route in itertools.permutations([j for j in range(n)], n):
		k = 1
		st = [route[0]]
		while (len(st) > 0) and (k < len(route)):
			if flights[st[len(st) - 1]][route[k]]:
				st.append(route[k])
				k += 1
			else:
				st.pop()
		if k == len(route):
			res = ""
			for l in route:
				res += zip_codes[l]
			if (lowest_zip == "") or (res < lowest_zip):
				lowest_zip = res

	print lowest_zip				
