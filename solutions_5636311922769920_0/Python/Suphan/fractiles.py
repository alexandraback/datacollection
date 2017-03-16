f = open('D-small-attempt0.in')
fw = open('D-small.out', 'w')

cases = int(f.readline())
for case in range(cases):
	K, C, S = map(int, f.readline().split())
	if K % C == 0:
		req = K / C
	else:
		req = (K / C) + 1

	if req > S:
		fw.write('Case #' + str(case + 1) + ': IMPOSSIBLE\n')
		continue

	solution = []
	for i in range(req):
		pos = 0
		
		for j in range(C):
			original_check_pos = (i * C) + j
			if original_check_pos >= K:
				break
			pos += original_check_pos * (K ** (C - j - 1))
		solution.append(pos + 1)

	fw.write('Case #' + str(case + 1) + ': ' + ' '.join(map(str, solution)) + '\n')

fw.close()
f.close()
