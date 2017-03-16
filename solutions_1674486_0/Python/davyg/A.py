
def accessible(childs, i, record):
	if i in record:
		return record[i]
	r = [i]
	for x in childs[i]:
		r += accessible(childs, x, record)
	record[i] = r
	return r

def work(i):
	N = int(raw_input())
	fathers = []
	childs = []
	record = {}
	for j in range(0, N):
		childs.append([])
		fathers.append([])
	for j in range(0, N):
		l = map(int, raw_input().split())
		M = l[0]
		for k in l[1:]:
			fathers[j].append(k-1)
			childs[k-1].append(j)
	for x in childs:
		if len(x) > 1:
			l = []
			for j in x:
				a = accessible(childs, j, record)
				for z in a:
					if z in l:
						print("Case #{i}: Yes".format(i=i+1))
						return
				l += a
	print("Case #{i}: No".format(i=i+1))

T = int(raw_input())
for i in range(0, T):
	work(i)
