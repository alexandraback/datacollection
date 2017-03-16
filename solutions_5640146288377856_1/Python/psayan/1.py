case = "Case #"
data = []
t = input()
for idx in range(t):
	score = 0
	r, c, w = map(int, raw_input().split())
	cells = r * c
	if w == 1 or w == cells:
		data.append(cells)
	elif r == 1:
		score = cells / w
		score += w - 1
		if cells % w:
			score += 1
		data.append(score)
	else:
		score = (c / w) * (r - 1)
		score += c / w
		score += w - 1
		if c % w:
			score += 1
		data.append(score)

for idx in range(t):
	print case + str(idx + 1) + ": " + str(data[idx])
