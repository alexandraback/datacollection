fin=open('B-small-attempt1.in','r')
T=int(fin.readline())
# from numpy.random import randint
# T = 2
# inp = ['-','-+']

file('B-small-attempt1.out','w')
f=open('B-small-attempt1.out','w')
# file('B-small','w')
# f=open('B-small','w')


for time in xrange(T):
	S = fin.readline().strip()
	if S == '':
		f.write('Case #'+str(time+1)+': 0\n')
	else:
		num_segs = 1
		for i in xrange(1,len(S)):
			if S[i] != S[i-1]:
				num_segs += 1
		if num_segs == 1:
			if S[0] == '+':
				f.write('Case #'+str(time+1)+': 0\n')
			elif S[0] == '-':
				f.write('Case #'+str(time+1)+': 1\n')
		else:
			if num_segs%2 == 0:
				if S[0] == '+':
					f.write('Case #'+str(time+1)+': '+str(num_segs)+'\n')
				elif S[0] == '-':
					f.write('Case #'+str(time+1)+': '+str(num_segs-1)+'\n')
			else:
				if S[0] == '+':
					f.write('Case #'+str(time+1)+': '+str(num_segs-1)+'\n')
				elif S[0] == '-':
					f.write('Case #'+str(time+1)+': '+str(num_segs)+'\n')

f.close()