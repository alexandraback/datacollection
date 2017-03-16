import sys


def calc():
	N = input()
	f = [int(x)-1 for x in raw_input().split()]

	# for paired nodes only
	db = [None for i in range(N)]	# paired node
	mx = [None for i in range(N)]	# max length on this node
	# for all nodes
	hd = [None for i in range(N)]	# rep head node of this node
	ln = [None for i in range(N)]	# length to the rep head
	for i in range(N):
		if f[f[i]] == i:
			db[i] = f[i]
			mx[i] = 0
			hd[i] = i
			ln[i] = 0

	mc = 0
	for i in range(N):
		if hd[i] is not None:
			continue
		stack = [i]
		hd[i] = -1
		while hd[f[i]] is None:
			i = f[i]
			stack.append(i)
			hd[i] = -1
		if hd[f[i]] == -1:
			# cycle detected
			l = 1
			fg = True
			while stack:
				j = stack.pop()
				if j == f[i]:
					fg = False
					mc = max(mc, l)
				hd[j] = -2
				if fg:
					l += 1
		elif hd[f[i]] == -2:
			pass
		else:
			l = 1
			while stack:
				j = stack.pop()
				hd[j] = hd[f[i]]
				ln[j] = ln[f[i]] + l
				mx[hd[j]] = max(mx[hd[j]], ln[j])
				l += 1
	#print db
	#print mx
	#print hd
	#print ln
	ans1 = mc
	ans2 = 0
	for i in range(N):
		if hd[i] == i:
			ans2 += mx[i] + 1
	return max(ans1, ans2)


def main():
	T = input()
	for t in range(T):
		ans = calc()
		print 'Case #%d: %s'%(t+1, ans)


if __name__ == '__main__':
	main()
