fin=open('A-small-attempt0.in','r')
T=int(fin.readline())
# T = 5
# inp = [0,1,2,11,1692]

file('A-small-attempt0.out','w')
f=open('A-small-attempt0.out','w')


for time in xrange(T):
	N = int(fin.readline())
	if N == 0:
		# print 'Case #'+str(time+1)+': INSOMNIA\n'
		f.write('Case #'+str(time+1)+': INSOMNIA\n')
	else:
		count = 0
		h = {str(i):False for i in xrange(10)}
		cur_num = 0
		while count < 10:
			cur_num += N
			for d in list(str(cur_num)):
				if not h[d]:
					h[d] = True
					count += 1

		# print 'Case #'+str(time+1)+': '+str(cur_num)+'\n'
		f.write('Case #'+str(time+1)+': '+str(cur_num)+'\n')

f.close()