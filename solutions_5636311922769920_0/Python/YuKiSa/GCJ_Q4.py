import numpy as np

read = open('input.txt', 'rb')
write = open('output.txt', 'wb')

t_num = int(read.readline())
for epoch in range(t_num) :
	write.write('Case #'+str(epoch+1)+': ')
	fetch = read.readline().strip().split()
	k = int(fetch[0]); c = int(fetch[1]); s = int(fetch[2]);
	for i in range(1, k+1) : write.write(str(i)+' ')
	write.write('\n')
