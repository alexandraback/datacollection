import sys

def main(f,o):
	f.readline()
	for i,l in enumerate(f):
		l = l
		o.write('Case #%d: %s'%(i+1,rec_fun(l)))

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

with open('input.file') as f, open('output','w') as o:
	main(f,o)
