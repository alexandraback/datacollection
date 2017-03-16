d={}
d['a']='y'
d['b']='h'
d['c']='e'
d['d']='s'
d['e']='o'
d['f']='c'
d['g']='v'
d['h']='x'
d['i']='d'
d['j']='u'
d['k']='i'
d['l']='g'
d['m']='l'
d['n']='b'
d['o']='k'
d['p']='r'
d['q']='z'
d['r']='t'
d['s']='n'
d['t']='w'
d['u']='j'
d['v']='p'
d['w']='f'
d['x']='m'
d['y']='a'
d['z']='q'
d[' ']=' '
T=int(raw_input())
for t in range(T):
	s=raw_input()
	n=range(len(s))
	tt=""
	for i in n:
		tt+=d[s[i]]
	print "Case #%d:"%(t+1),tt
