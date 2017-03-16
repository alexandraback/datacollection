mult_tab = {'1':{'1':'1','i':'i','j':'j','k':'k'}, 
		'i':{'1':'i','i':'-1','j':'k','k':'-j'},
		'j':{'1':'j','i':'-k','j':'-1','k':'i'},
		'k':{'1':'k','i':'j','j':'-i','k':'-1'}}

def mult(a,b):
	a_ = a
	minus = 1
	if len(a) == 2:
		a_ = a[1]
		minus = -1
	b_ = b
	if len(b) == 2:
		b_ = b[1]
		minus = minus*-1

	res = mult_tab[a_][b_]

	if minus == -1 and len(res)==1:
		return '-'+mult_tab[a_][b_]
	elif minus == -1 and len(res)==2:
		return res[1]
	else:
		return mult_tab[a_][b_]

T=int(input())
for tc in range(1,T+1):
	[l,x]=[int(z) for z in input().split()]
	s = input()
	s = s*x
	i = False
	j = False
	k = False

	sol = '1'
	for ch in s:
		sol = mult(sol,ch)
		if not i and sol == 'i':
			i=True
			sol = '1'
		if i and not j and sol == 'j':
			j = True
			sol = '1'
		if i and j and not k and sol == 'k':
			k = True
			sol = '1'

	if i and j and k and sol == '1':
		print('Case #{_tc}: YES'.format(_tc=tc))
	else:
		print('Case #{_tc}: NO'.format(_tc=tc))

