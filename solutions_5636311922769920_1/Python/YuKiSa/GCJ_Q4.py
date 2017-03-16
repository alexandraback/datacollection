import numpy as np

read = open('input.txt', 'rb')
write = open('output.txt', 'wb')

t_num = int(read.readline())
for epoch in range(t_num) :
	write.write('Case #'+str(epoch+1)+':')
	fetch = read.readline().strip().split()
	k = int(fetch[0]); c = int(fetch[1]); s = int(fetch[2]);
	if c*s<k :
		write.write(' IMPOSSIBLE\n')
		continue
	glob_cnt = 0
	for i in range(s) : 
		i_sum = 0
		for j in range(c) : 
			i_sum *= k
			i_sum += (glob_cnt%k)
			glob_cnt += 1
		write.write(' '+str(i_sum+1))
	write.write('\n')

