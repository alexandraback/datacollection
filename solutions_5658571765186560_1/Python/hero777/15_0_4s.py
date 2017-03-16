f = open('a.txt','r')
f0 = open('output.txt','w')
a0 = [int(x) for x in f.readline().split()]
for index in range (0,a0[0]):
	print(index)
	x,y,z = [int(x) for x in f.readline().split()]
	f0.write('Case #')
	f0.write(str(index+1))
	f0.write(': ')
	if x==1:
		f0.write('GABRIEL')
		f0.write('\n')
		continue
	if x==2:
		if y*z%x == 0:
			f0.write('GABRIEL')
			f0.write('\n')
		else:
			f0.write('RICHARD')
			f0.write('\n')
		continue
	if x==3:
		if (y*z%x !=0 or min(y,z) <2):
			f0.write('RICHARD')
			f0.write('\n')
		
		else:
			f0.write('GABRIEL')
			f0.write('\n')
		continue
	if x==4:
		if (max(y,z) < 4 or y*z%x !=0 or min(y,z) <= 2):
			f0.write('RICHARD')
			f0.write('\n')
			
		else:
			
			f0.write('GABRIEL')
			f0.write('\n')
	if x==5:
		if (max(y,z) < 5 or y*z%x !=0 or min(y,z) <= 2):
			f0.write('RICHARD')
			f0.write('\n')
		else:
			if (y*z == 15):
				f0.write('RICHARD')
				f0.write('\n')
			else:
				f0.write('GABRIEL')
				f0.write('\n')
	if x == 6:
		if (max(y,z) < 6 or y*z%x !=0 or min(y,z) <= 3):
			f0.write('RICHARD')
			f0.write('\n')
		else:
			f0.write('GABRIEL')
			f0.write('\n')
	if x > 6:
		f0.write('RICHARD')
		f0.write('\n')		
	
		



