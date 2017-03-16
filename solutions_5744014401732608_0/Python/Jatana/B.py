import sys

sys.stdin = open('input.txt')
sys.stdout = open('output123.txt', 'w')

def check(matrix):
	global nways
	n = len(matrix)
	global cnt
	cnt = 0
	def dfs(v):
		global cnt
		if v == n - 1:
			cnt += 1
			return
		for i in range(n):
			if matrix[v][i]:
				dfs(i)
	dfs(0)
	# print(cnt, nways, matrix)
	return cnt == nways



matrix = [
	[0,1,0,0,1],
	[0,0,1,1,0],
	[0,0,0,0,1],
	[0,0,1,0,1],
	[0,0,0,0,0]
]


def gen(rez, objs, cur, i):
	# print(cur, i)
	if i == len(objs):
		rez.append(cur[::])
		return
	cur.append(objs[i])
	gen(rez, objs, cur, i + 1)
	cur.pop()
	gen(rez, objs, cur, i + 1)



def next(i, j, n):
	j += 1
	if j == n:
		i += 1
		j = 0
	return i, j

# table =

def gen_table(i, j, n):
	global rez
	global table
	if i == n:
		# print(table)
		if check(table):
			rez = [x[::] for x in table]
		return
		

	x, y = next(i, j, n)
	if i < j:
		table[i][j] = 1
		gen_table(x, y, n)
		table[i][j] = 0
		gen_table(x, y, n)
	else:
		gen_table(x, y, n)



# rez = []
# gen(rez, [1, 4, 5], [], 0)
# print(rez)
def solve(n, nways):
	combs = []
	for i in range(n - 1):
		t = [j for j in range(i + 1, n)]
		r = []
		gen(r, t, [], 0)
		r = [[i, x] for x in r]
		combs.extend(r)
	all_combs = []
	gen(all_combs, combs, [], 0)
	for comb in all_combs:
		matrix = [[0 for i in range(n)] for i in range(n)]
		for v, cons in comb:
			for con in cons:
				matrix[v][con] = 1
		if check(matrix, nways):
			for x in matrix:
				for y in x:
					print(y, end='')
				print()
			exit()



cnt_tests = int(input())
nways = 0
table = []
rez = []

for i in range(cnt_tests):
	n, nways = map(int, input().split())
	table = [[0 for i in range(n)] for i in range(n)]
	rez = None
	gen_table(0, 0, n)
	print('Case #%d: ' % (i + 1), end='')
	if rez is None:
		print("IMPOSSIBLE")
	else:
		print("POSSIBLE")
		for x in rez:
			for y in x:
				print(y, end='')
			print()