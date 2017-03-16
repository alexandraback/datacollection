#!/usr/bin/env python
# coding: utf-8

def reader(n, st):
	temp = st.split(' ')
	ans = []
	for i in xrange(n):
		ans.append([int(temp[2*i]), int(temp[2*i +1])])
	return ans


if __name__ == "__main__":
	with open('input.txt', 'r') as fin:
		with open('output.txt', 'w') as fout:
			t = int(fin.readline())
			for i in xrange(t):
				n, m = map(int, fin.readline().split(' '))
				box = reader(n, fin.readline())
				toys = reader(m, fin.readline())
				ans = [[0 for b in xrange(n+1)] for t in xrange(m+1)]
				
				for j in xrange(m):
					if box[0][1] == toys[j][1]:
						if j>0:
							ans[j][0] = ans[j-1][0]+min(box[0][0], toys[j][0])
						else:
							ans[j][0] = min(box[0][0], toys[j][0])
						k = min(box[0][0], toys[j][0])
						box[0][0] -= k
						toys[j][0] -= k
					else:
						ans[j][0] += ans[j-1][0]
				
				for j in xrange(n):
					if box[j][1] == toys[0][1]:
						if j>0:
							ans[0][j] += ans[0][j-1]+min(box[j][0], toys[0][0])
						else:
							ans[0][j] += min(box[j][0], toys[0][0])
						k = min(box[j][0], toys[0][0])
						box[j][0] -= k
						toys[0][0] -= k
					else:
						ans[0][j] += ans[0][j-1]
						
				for t in xrange(1, m):
					for b in xrange(1, n):
						if box[b][1] == toys[t][1]:
							ans[t][b] += min(box[b][0], toys[t][0])
							k = min(box[b][0], toys[t][0])
							box[b][0] -= k
							toys[t][0] -= k
						ans[t][b] += max(ans[t-1][b], ans[t][b-1])
				fout.write("Case #{0}: {1}\n".format(i+1, max(max(ans))))