import numpy as np

def check(seen) :
	for i in range(10) :
		if seen[i] == 0 : return False
	return True

read = open('input.txt', 'rb')
write = open('output.txt', 'wb')

t_num = int(read.readline())

for epoch in range(t_num) :
	num = int(read.readline())
	write.write('Case #'+str(epoch+1)+': ')
	if num==0 :
		write.write('INSOMNIA\n')
	else :
		seen = np.zeros((10,), dtype=np.int32)
		now_num = 0
		while not check(seen) :
			now_num += num
			temp_num = now_num
			while temp_num>0 :
				seen[temp_num%10] = 1
				temp_num /= 10
		write.write(str(now_num)+'\n')