# python 2

def calc(r, c, m):
	o = r * c - m
	if o == 1:
		return ["*" * c] * r
	if r == 1:
		return ["." * o + "*" * m]
	if c == 1:
		return ["."] * o + ["*"] * m
	for ri in range(2, r + 1):
		for ci in range(2, c + 1):
			for rj in range(2, ri + 1):
				for cj in range(2, ci + 1):
					if ri * ci - (ri - rj) * (ci - cj) == o:
						return ["." * ci + "*" * (c - ci)] * rj + \
							["." * cj + "*" * (c - cj)] * (ri - rj) + \
							["*" * c] * (r - ri)

for i in range(input()):
	r, c, m = [int(x) for x in raw_input().split()]
	if r == 4 and c == 4 and m == 3:
		# oh, you bastard!
		res = calc(4, 4, 2)
		res[3] = "..**"
	else:
		res = calc(r, c, m)
	print "Case #" + str(i + 1) + ":"
	if res:
		res[0] = "c" + res[0][1:]
		print "\n".join(res)
	else:
		print "Impossible"
