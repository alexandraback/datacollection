import sys
from collections import defaultdict as ddict
sys.setrecursionlimit(100000)
def main(f,o):
	t = int(f.readline())
	for t2 in range(t):
		n = int(f.readline())
		counts = ddict(int)
		for i,l in enumerate(f):
			for j in [int(w) for w in l.split(' ')]:
				counts[j] += 1
			if i == 2*n-2:break
		list_int = []
		for k,c in counts.items():
			if c % 2 == 1:
				list_int.append(k)
		o.write('Case #%d: '%(t2+1))
		o.write(' '.join([str(k) for k in sorted(list_int)]))
		o.write('\n')

# 		print(sorted(list_int))


# 		o.write('Case #%d: %s'%(i+1,rec_fun(l)))
# 		if i == 2*n-1 : break

def rec_fun(w):
	if not w: return ''
	letter = ''
	pos = 0
	for i,l in enumerate(w):
		if l >= letter:
			letter = l
			pos = i
	return letter+rec_fun(w[:pos])+str(w[pos+1:])
# 	print('lol')

with open('input') as f, open('output','w') as o:
	main(f,o)
