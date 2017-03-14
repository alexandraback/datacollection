from sys import stdin
from math import ceil, sqrt
def rline():
	return stdin.readline().rstrip()
def sign(p):
	if p < 0:
		return -1
	elif p > 0:
		return 1
	else:
		return 0

def same_quadrant((x,y), (p,q)):
	return sign(x) == sign(p) and sign(y) == sign(q)
	
def already_in_doubles((x,y)):
	for (p,q) in non_doubles:
		if same_quadrant((x,y),(p,q)):
			if x*q == y*p:
				return True
	return False

for l in range(int(rline())):
	(h,w,d) = map(int, rline().split())
	field = [rline()[1:-1] for i in range(int(h))]
	field = field[1:-1]
	h = h-2
	w = w-2
	h_fields = d/h + 1
	w_fields = d/w + 1
	bigfield = []
	for hf in range(-h_fields, h_fields + 1):
		for sub_h in range(h):
			row = []
			for wf in range(-w_fields, w_fields + 1):
				for sub_w in range(w):
					if hf % 2 == 1:
						y = h - sub_h - 1
					else:
						y = sub_h
					if wf % 2 == 1:
						x = w - sub_w - 1
					else:
						x = sub_w
					cell = field[y][x]
					if cell == 'X' and hf == 0 and wf == 0:
						cell = 'O'
					row.append(cell)
			bigfield.append("".join(row))
	mirrored = []
	for y in range(len(bigfield)):
		for x in range(len(bigfield[y])):
			cell = bigfield[y][x]
			if cell == 'X':
				mirrored.append((x,y))
			elif cell == 'O':
				self = (x,y)
	mirrored = map(lambda (x,y): (x-self[0], y-self[1]), mirrored)
	mirrored = filter(lambda (x,y): x*x + y*y <= d*d, mirrored)
	non_doubles = []
	for (x,y) in mirrored:
		if not(already_in_doubles((x,y))):
			non_doubles.append((x,y))
				

	print "Case #%s: %s " % (l+1, len(non_doubles))
