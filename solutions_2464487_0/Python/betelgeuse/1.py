import string
import math

fin = open("y:/A-small-attempt1.in")
fout = open("y:/output", 'w');
T = int(fin.readline())
for i in range(0, T):
	list = fin.readline().split(' ');
	r = int(list[0]);
	t = int(list[1]);
	# c = 0;
	# count = 2*r+1
	# while count <= t:
	# 	c=c+1
	# 	r=r+2
	# 	count = count+(2*r+1)
	# fout.write("Case #" + str(i+1) +": "+str(c)+'\n')
	#fout.write(str(r)+'\n')
	#fout.write(str(t)+'\n')
	c = (1 - 2*r + math.sqrt((2*r-1)*(2*r-1)+8*t))/4;
	#fout.write(str(c)+ '\n');
	cint = int(c);
	if(cint > 6):
		cint = int(c) - 5;
		while cint**2*2+2*r*cint-cint <= t:
			cint = cint + 1;
		fout.write("Case #" + str(i+1) +": "+str(cint-1));
	else:
		fout.write("Case #" + str(i+1) +": "+str(cint));
	fout.write('\n');