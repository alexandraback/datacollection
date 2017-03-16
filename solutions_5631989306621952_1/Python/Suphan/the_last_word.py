f = open('A-large.in')
fw = open('A-large.out', 'w')

cases = int(f.readline())
for case in range(cases):
	ans = ''
	letters = f.readline().strip()
	for c in letters:
		if len(ans) > 0 and c >= ans[0]:
			ans = c + ans
		else:
			ans = ans + c
	fw.write('Case #' + str(case + 1) + ': ' + ans + '\n')

fw.close()
f.close()
