from collections import defaultdict

def choose_one(not_copy, ps_copy, p_copy, n_copy, tops, ow, idx):
	chosen = None
	for i in p_copy:
		#print tops, p_copy, tops[i], ow
		if not ow[tops[i][idx]][1]:
			chosen = i
			break
	if chosen is None:
		chosen = p_copy[-1]
	p_copy = [_ for _ in p_copy if _ != chosen]
	n_copy = [chosen]
	ow[tops[i][idx]][1] = [chosen]
	ow[tops[i][idx]][0] = [_ for _ in ow[tops[i][idx]][0] if _ != chosen]
	ps_copy.discard(chosen)
	not_copy.add(chosen)

def solve(N, tops):
	f_w = defaultdict(list) 
	s_w = defaultdict(list) 
	for i in xrange(N):
		f_w[tops[i][0]].append(i)
		s_w[tops[i][1]].append(i)
	not_copy = set([])
	ps_copy = set([])
	f_p = {} 
	s_p = {} 
	for w in f_w:
		p_copy, n_copy = [], []
		if len(f_w[w]) == 1:
			not_copy.add(f_w[w][0])
			n_copy.append(f_w[w][0])
		else:
			for i in f_w[w]:
				if len(s_w[tops[i][1]]) == 1:
					n_copy.append(i)
					not_copy.add(i)
				else:
					p_copy.append(i)
					ps_copy.add(i)
		f_p[w] = [p_copy, n_copy]
	for w in s_w:
		p_copy, n_copy = [], []
		if len(s_w[w]) == 1:
			not_copy.add(s_w[w][0])
			n_copy.append(s_w[w][0])
		else:
			for i in s_w[w]:
				if len(f_w[tops[i][0]]) == 1:
					n_copy.append(i)
					not_copy.add(i)
				else:
					p_copy.append(i)
					ps_copy.add(i)
		s_p[w] = [p_copy, n_copy]
	#print s_p
	ct = 0
	for w in f_p:
		#print w, f_p[w]
		p_copy, n_copy = f_p[w]
		if not n_copy and p_copy:
			choose_one(not_copy, ps_copy, p_copy, n_copy, tops, s_p, 1)
	for w in s_p:
		p_copy, n_copy = s_p[w]
		if not n_copy and p_copy:
			choose_one(not_copy, ps_copy, p_copy, n_copy, tops, f_p, 0)
	return len(ps_copy)


T = int(raw_input())
for case in range(1, T+1):
	N = int(raw_input())
	tops = [raw_input().strip().split() for _ in xrange(N)]
	print "Case #{}: {}".format(case, str(solve(N, tops)))