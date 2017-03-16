__author__ = 'leha'

from time import time
from math import pi

def nextCase():
    fileName = "C.in"
    fileName = "C-small-attempt5.in"
#    fileName = "B-small-practice.in"
    fileName = "C-large.in"
#    fileName = "B-large-practice.in"
    input = open(fileName, 'r')
    T = int(input.readline())
    for i in range(T):
        R, C, M = tuple([int(x) for x in input.readline().split(' ')])
        yield R, C, M

def convert(R):
	r = ""
	for x in range(len(R)):
		r += "\n" + "".join(R[x])
	return r

def solve(T):
	R, C, M = T

	free = R*C - M
	if 1 == R or 1 == C:
#		if free > 1:
			r = "c" + "."*(free - 1) + "*"*(M)
			if 1 == R: return "\n" + r
			else: return "".join(["\n" + d for d in r])
#		return "\nImpossible"

	if 1 == free:
		r = [["*" for i in range(C)] for j in range(R)]
		r[0][0] = "c"
		return convert(r)

	for x in range(2, R + 1):
		for y in range(2, C + 1):
			notIn = free - x*y
			if x*y <= free and (notIn <= x + y) and (0 == notIn or notIn >= 2):
#				print("!", x, y)
				r = [["*" for i in range(C)] for j in range(R)]
				for i in range(x):
					for j in range(y):
						r[i][j] = "."
				r[0][0] = "c"
				if notIn >= 2:
					if x < R - 1 and notIn <= y:
						for j in range(notIn):
							r[x][j] = "."
						return convert(r)
					elif y < C - 1 and notIn <= x:
						for i in range(notIn):
							r[i][y] = "."
						return convert(r)
					else:
						for hPart in range(2, notIn - 1):
							vPart = notIn - hPart
							if (x < R) and (hPart <= y) and (y < C) and (vPart <= x):
								for i in range(vPart):
									r[i][y] = "."
								for j in range(hPart):
									r[x][j] = "."
								return convert(r)
						for hPart in range(1, notIn - 1):
							vPart = notIn - hPart
							if (x < R) and (hPart <= y + 1) and (y < C) and (vPart <= x + 1) and (3 <= hPart or 3 <= vPart):
								for i in range(vPart):
									r[x - i][y] = "."
								for j in range(hPart + 1):
									r[x][y - j] = "."
								return convert(r)
				elif 0 == notIn: return convert(r)

	return "\nImpossible"

def stars(s):
	return sum(1 for c in s if '*' == c)

start = time()

i = 1
for T in nextCase():
    r = solve(T)
#    if "\nImpossible" == r: print("!", T)
 #   elif stars(r) != T[2]: print("!!", T)
    print("Case #%d: %s" % (i, r))
    i += 1

#print(time() - start)
__author__ = 'leha'
