def join(a, sep=""):
	return sep.join(str(c) for c in a)

def njoin(a):
	return "\n".join(c for c in a)

def transpose(ans):
	if ans[0] == "Impossible":
		return ["Impossible"] + transpose(ans[1:])
	
	R,C = len(ans), len(ans[0])
	R,C = C,R
	
	ans2 = [None] * R
	for i in range(R):
		ans2[i] = [None] * C
		for j in range(C):
			ans2[i][j] = ans[j][i]
			
	return ["".join(a) for a in ans2]


def mines(R, C, M, debug = False):
	blanks = R * C - M
	assert (blanks >= 1)
	impossible = False
	ans = []
	
	if R > C: return transpose(mines(C, R, M, debug))
	
	if R == 1:
		# .**** 0.*** 00.** 000.*
		ans = [""]
		ans[0] = ['c'] + ['.'] * (blanks-1) + ['*'] * (R*C-blanks)
	elif R == 2:
		ans = [['*'] * C for i in range(2)]
		for i in range(blanks):
			ans[i % 2][i // 2] = '.'
		ans[0][0] = 'c'
		
		if (blanks % 2 != 0 and blanks > 1) or blanks == 2:
			# !***  1!**  001!**
			# !***  !***  00!***
			impossible = True
			
	else: # R,C >= 3
		ans = [(['*'] * C) for i in range(R)]
		impossible = (blanks in {2,3,5,7})
		# 135
		# 246
		# 789
		first8 = [(0,0), (1,0), (0,1), (1,1), (0,2), (1,2),  (2,0), (2,1)]
		
		if blanks <= 8:
			spot9 = False
			for i, j in first8[:blanks]:
				ans[i][j] = '.'
		else:
			for i,j in first8:
				ans[i][j] = '.'
			blanks -= 8
			
			spot9 = False
			if blanks % 2 != 0:
				ans[2][2] = '.'
				blanks -= 1
				spot9 = True
			
			x = 3
			while x < C and blanks >= 2:
				ans[0][x] = '.'
				ans[1][x] = '.'
				x += 1; blanks -= 2
			
			y = 3
			while y < R and blanks >= 2:
				ans[y][0] = '.'
				ans[y][1] = '.'
				y += 1; blanks -= 2
			
			y,x = 2,2
			if spot9: x += 1
			while blanks >= 1:
				ans[y][x] = '.'
				x += 1
				if x == C:
					x = 2
					y += 1
				blanks -= 1
		
		ans[0][0] = 'c'

	ans = ["".join(a) for a in ans]
	
	print(join(ans, "\n"), "\n")
	print(ans)
	if impossible:
		ans = ["Impossible"] + ans
	else:
		test(ans[:])

	return ans

def test(ans_):
	#return
	ans = ans_[:]
	
	R,C = len(ans), len(ans[0])
	
	def neighbours(i, j, R, C):
		ret = set()
		for i2 in {i-1,i,i+1} - {-1,R}:
			for j2 in {j-1,j,j+1} - {-1,C}:
				ret.add((i2,j2))
		return ret - {(i,j)}
	print( neighbours(1,1, 3,3) )

	def neighbourmines(ans, i, j, R, C):
		cnt = 0
		for i2, j2 in neighbours(i, j, R, C):
			if not j2 in range(len(ans[i2])): print(j2, ans[i2])
			if ans[i2][j2] == '*':
				cnt += 1
		return cnt

	assert len(ans) == R
	for i in range(R):
		ans[i] = [c for c in ans[i]]
	
	foundc = True
	while foundc:
		foundc = False
		print("\n".join("".join(a) for a in ans), "\n:)\n")
		for i in range(R):
			for j in range(C):
				if ans[i][j] == 'c':
					foundc = True
					ans[i][j] = str(neighbourmines(ans, i, j, R, C))
					if ans[i][j] == '0':
						for (i2, j2) in neighbours(i, j, R, C):
							if ans[i2][j2] == '.':
								ans[i2][j2] = 'c'

	for i in range(R):
		assert '.' not in ans[i]
	print("{!r}".format(ans))
	ans = ["".join(a) for a in ans]

R,C = 2,3
B = 4
M = R*C-B
#print("\n".join(mines(R, C, M)))
#print("{!r}".format(mines(R, C, M)))

debug = False
#debug = True

fi = "C-eg.in"
fo = "C-eg.out"
fi = "C-small-attempt0.in"
fo = "C-small-attempt0.out"
fi = "C-small-attempt2.in"
fo = "C-small-attempt2.out"
fi = "C-large.in"
fo = "C-large.out"

with open(fi) as fi:
	with open(fo, 'w') as fo:
		n = int(fi.readline())
		for i in range(n):
			R,C,M = [int(n) for n in fi.readline().split()]

			if debug:
				print ("\n", file=fo)

			print( "Case #{0}:".format(i+1), file=fo )

			if debug: print( "# {}*{}, {}".format(R, C, M), "\n", file=fo)

			for l in mines(R, C, M, debug):
				print(l, file=fo)
				if l == "Impossible" and not debug: break
