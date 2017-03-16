import sys
import collections

T = int(raw_input())

# f=0: forward, 1: backward
def add_circle(cur_circle, kids, f):
	circles = []

	#print cur_circle, kids

	tc = cur_circle[-1]
	kid1 = [k for k in kids if k[f] == tc]  # always one or zero if f==0
	kid = []

	if not kid1:
		if f == 0:
			return []
		elif f == 1:
			return [ cur_circle ]
	else:
		if f == 0:
			if kid1[0][1] == cur_circle[0]: # circle
				return [ cur_circle ]
			else:
				kid = kid1[0]   # always one
				new_kids = list(kids)
				new_kids.remove(kid)
				bff = kid[1]

				if bff == cur_circle[-2]:
					circles += add_circle(cur_circle, new_kids, 1)
				else:
					circles += add_circle(cur_circle + [bff], new_kids, 0)
		else: # f=1
			for kid in kid1:
				new_kids = list(kids)
				new_kids.remove(kid)
				new = kid[0]

				circles += add_circle(cur_circle + [new], new_kids, f)

		#print circles
		return circles

	'''
	bc = cur_circle[0]
	kid1 = [k for k in kids if k[0] == bc]  # always one or zero
	if kid1:
		new_kids = list(kids).remove(kid1[0])
		c1 = add_circle(kid1[0][1] + cur_circle, new_kids)
	'''     

for t in range(1, T+1):
	N = int(raw_input())
	fs = map(int, raw_input().split())

	kids = zip(range(1,N+1), fs)

	num = 0

	for i in range(N):
		ks = list(kids)

		circle = list(ks.pop(i))
		circles = add_circle(circle, ks, 0)

		for c in circles:
			n = len(c)
			if n > num:
				num = n



	'''
	kids_fl = range(1,N+1) + fs
	cnt = collections.Counter(kids_fl)
	cnt3 = [ k for k,v in cnt.items() if v > 2]

	print kids, kids_fl, cnt
	print cnt3

	fs_d, fs_m = [], []
	for c in cnt3:
		if cnt[c] > 3: 
			fs_d.append(c)
		bff = kids[c-1][1]
		if kids[bff-1][1] == c:
			fs_m.append(c)

	print fs_d, fs_m

	num = 0

	for i in range(N):
		ks = list(kids)

		circle = list(ks.pop(i))
		f = 0
		idx = -1

		while ks:
			c = circle[idx]
			kid = [ k for k in ks if k[f] == c ]
			#print kid
			if not kid:
				if f == 0 and idx == -1:
					f = 1
					continue
				elif f == 1 and idx == -1:
					f = 0
					idx = 0
					continue
				elif f == 0 and idx == 0:
					f = 1
					continue
				elif f == 1 and idx == 0:
					break

			kid = kid[0]
			bff = kid[int(not f)]
			if not bff in circle:
				circle.append(bff) 
			ks.remove(kid)

		print circle
		n = len(circle)
		if n > num:
			num = n
	'''


	print 'Case #%d: %d' % (t, num)
	print N, fs
