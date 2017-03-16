def gen(kb,s):
	if s==1:
		return kb
	l=[]
	g=gen(kb,s-1)
	for x in kb:
		for y in g:
			l.append(x+y)
	return l

def occ(st,wd):
	cnt = srt = 0
	while True:
		srt = st.find(wd,srt)+1
		if srt>0:
			cnt=cnt+1
		else:
			return cnt

T=int(input())
for tc in range(1,T+1):
	[k,l,s]=[int(x) for x in input().split()]
	kb = list(input())
	wd = input()
	poss = gen(kb,s)
	data = [occ(x,wd) for x in poss]
	req = max(data)
	sol = req-sum(data)/len(data)
	print('Case #{_t}: {_s}'.format(_t=tc,_s=sol))
