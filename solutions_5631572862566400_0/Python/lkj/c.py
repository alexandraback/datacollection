import itertools

def findallcircles(n,f,pred):
	left = set(range(n))
	cl = []
	while len(left) > 0:
		ci = left.pop()
		left.add(ci)
		cc = []
		#print('fac iter', cl, cc, ci, left)
		while ci not in cc:
			if ci not in left:
				break
			cc.append(ci)
			ci = f[ci]
		else:
			cl.append(cc[cc.index(f[cc[-1]]):])
		left.difference_update(set(cc))
	return cl

def dfsd(n,f,pred,root):
	q = [root]
	deepest = []
	while len(q) > 0:
		cn = q[0]
		q.pop(0)
		q.extend(pred[cn])
		if len(pred[cn]) == 0:
			currc = [cn]
			c = cn
			while c != root:
				c = f[c]
				currc.append(c)
			if len(currc) > len(deepest):
				deepest = currc
	return deepest

def maxncext(n,f,pred,nc):
	pred[nc[0]].remove(nc[1])
	pred[nc[1]].remove(nc[0])
	c1 = dfsd(n,f,pred,nc[0]) + [nc[1]]
	c2 = dfsd(n,f,pred,nc[1]) + [nc[0]]
	pred[nc[0]].append(nc[1])
	pred[nc[1]].append(nc[0])
	return c1 + list(reversed(c2[:-2]))
	#print('mne',nc,c1,c2)
	#if len(c1) > len(c2):
	#	return c1
	#return c2

def findmaxncc(n,f,pred,ncc):
	ncl = [maxncext(n,f,pred,nc) for nc in ncc]
	#print('fmn', ncl)
	return list(itertools.chain.from_iterable(ncl))


def solve(n,f):
	pred = [list() for i in range(n)]
	for i in range(n):
		pred[f[i]].append(i)
	cl = findallcircles(n,f,pred)
	ncc = [c for c in cl if len(c) == 2]
	#print(cl, ncc, f, pred, findmaxncc(n,f,pred,ncc))
	return max(len(findmaxncc(n,f,pred,ncc)), max([len(c) for c in cl]))


tc = int(input())
for t in range(1, tc+1):
	n = int(input())
	f = [int(x)-1 for x in input().split()]
	print('Case #%i: %i' % (t, solve(n,f)))
