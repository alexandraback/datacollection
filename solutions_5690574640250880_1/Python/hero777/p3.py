f = open('C-large.in', 'r')
f0 = open('output.txt', 'w')
a0 = [int(x) for x in f.readline().split()];
for j in range (0, a0[0]):
	f0.write('Case #')
	f0.write(str(j+1))
	f0.write(':\n')
	a = [int(x) for x in f.readline().split()];
	if a[2] > a[0]*a[1]:
		break
	b = min(a[0], a[1]);
	if b==1:
		if (a[0] == 1):
			for i in range (0, a[2]):
				f0.write('*')
			for i in range (0, a[1]-a[2]-1):
				f0.write('.')
			f0.write('c\n')
		else:
			for i in range (0, a[2]):
				f0.write('*\n')
			for i in range (0, a[0]-a[2]-1):
				f0.write('.\n')
			f0.write('c\n')
		continue
	elif (a[2] == a[0]*a[1]-1):
		f0.write('c')
		for i in range (0,a[1]-1):
			f0.write('*')
		f0.write('\n')
		for k in range (0, a[0]-1):
			for i in range (0, a[1]):
				f0.write('*')
			f0.write('\n')
		continue
	else:
		S = a[1]*a[0]-a[2]
		print(S)
		y = 0
		for i in range (2, a[1]+1):
			q = int(S/i)
			r = S%i
			print(q)
			print(r)
			if (((r != 1) & (a[1]*q + r <= a[1]*a[0]) & (q >= 2))| ((r == 1) & (a[1]*q + r <= a[1]*a[0]) & (q > 2) & (i > 3))):
				y = i				
				break
		print(y)	
		if (y == 0):
			y1 = 0
			for i in range (2, a[0]+1):
				q = int(S/i)
				r = S%i
				if (((r !=1) & (a[0]*q + r <= a[1]*a[0]) & (q >=2))| ((r == 1) & (a[0]*q + r <= a[1]*a[0]) & (q > 2) & (i > 3))):
					y1 =i
					break
			if (y1 == 0):
				f0.write('Impossible\n')
				continue
			else:
				q = int(S/y1)
				r = S%y1
				if (r == 1):
					f0.write('c')
					for i in range (0, q):
						f0.write('.')
					for i in range (0, a[1]-q-1):
						f0.write('*')
					f0.write('\n')
					for i in range (0,q+1):
						f0.write('.')
					for i in range (0, a[1]-q-1):
						f0.write('*')
					f0.write('\n')
					for k in range (0, y1-3):
						for i in range (0, q):
							f0.write('.')
						for i in range (0, a[1]-q):
							f0.write('*')
						f0.write('\n')
					for i in range (0,q-1):
						f0.write('.')
					for i in range (0,a[1]-q+1):
						f0.write('*')
					for k in range (0, a[0]-y1):
						for i in range (0,a[1]):
							f0.write('*')
						f0.write('\n')
					continue		
				f0.write('c')
				for i in range (0, q-1):
					f0.write('.')
				if (r >0):
					f0.write('.')
					r = r-1
					for i in range (0, a[1]-q-1):
						f0.write('*')
					f0.write('\n')
				else:
					for i in range (0, a[1]-q):
						f0.write('*')
					f0.write('\n')
				for k in range (0, y1-1):
					for i in range (0, q):
						f0.write('.')
					if (r>0):
						f0.write('.')
						r = r-1
						for i in range (0, a[1]-q-1):
							f0.write('*')
						f0.write('\n')
					else:
						for i in range (0, a[1]-q):
							f0.write('*')
						f0.write('\n')
				for k in range (0, a[0]-y1):
					for i in range (0, a[1]):
						f0.write('*')
					f0.write('\n')
			
		else:
			q = int(S/y)
			r = S%y
			if (r==1):
				f0.write('c')
				for i in range (0, y-1):
					f0.write('.')
				for i in range (0, a[1]-y):
					f0.write('*')
				f0.write('\n')
				for k in range (0, q-2):
					for i in range (0,y):
						f0.write('.')
					for i in range (0, a[1]-y):
						f0.write('*')
					f0.write('\n')
				for i in range (0, y-1):
					f0.write('.')
				for i in range (0, a[1]-y+1):
					f0.write('*')
				f0.write('\n')
				for i in range (0,2):
					f0.write('.')
				for i in range (0, a[1]-2):
					f0.write('*')
				f0.write('\n')
				for k in range (0, a[0]-q-1):
					for i in range (0, a[1]):
						f0.write('*')
					f0.write('\n')
				continue
			f0.write('c')
			for i in range (0, y-1):
				f0.write('.')
			for i in range (0, a[1]-y):
				f0.write('*')
			f0.write('\n')
			for k in range (0, q-1):
				for i in range (0,y):
					f0.write('.')
				for i in range (0, a[1]-y):
					f0.write('*')
				f0.write('\n')
			if (r>0):
				for i in range (0,r):
					f0.write('.')
				for i in range (0, a[1]-r):
					f0.write('*')
				f0.write('\n')
				for k in range (0, a[0]-q-1):
					for i in range (0, a[1]):
						f0.write('*')
					f0.write('\n')
			else:
				for k in range (0, a[0]-q):
					for i in range (0, a[1]):
						f0.write('*')
					f0.write('\n')










				
			







