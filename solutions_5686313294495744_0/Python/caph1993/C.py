import sys

#in_file = "C-sample"
in_file = "C-small-attempt0"
sys.stdin = open(in_file+".in")
#sys.stdout = open(in_file+".out","w")

ntc = int(input())

for tc in range(ntc):
	N = int(input())
	left = dict(); l=0
	right = dict(); r=0
	q = []
	for _ in range(N):
		sl, sr = input().split()
		if sl not in left: left[sl]=l; l+=1
		if sr not in right: right[sr]=r; r+=1
		q.append((left[sl],right[sr]))
	
	# BRUTE
	ans = 0
	for z in range(1<<len(q)):
		l = [int((z&(1<<i))>0) for i in range(len(q))]
		w = sum(l)
		if w<=ans: continue
		ls = set()
		rs = set()
		for i,_ in enumerate(l):
			if l[i]:
				if q[i][0] in ls and q[i][1] in rs:
					w = 0
					break
				ls.add(q[i][0])
				rs.add(q[i][1])
		ans = max(ans, w)
	print('Case #%d: '%(tc+1),end='')
	print(N-ans)
