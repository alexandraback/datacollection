import numpy as np

def check(pk) :
	length = pk.shape[0]
	for i in range(length) :
		if pk[length-1-i] == 0 : return length-1-i
	return -1

def flip(pk, idx) :
	for i in range(idx+1) :
		if pk[i] == 1 : pk[i] = 0
		else : pk[i] = 1
	return pk

read = open('input.txt', 'rb')
write = open('output.txt', 'wb')

t_num = int(read.readline())
for epoch in range(t_num) :
	write.write('Case #'+str(epoch+1)+': ')
	line = read.readline().strip()
	n_line = np.zeros((len(line), ), dtype=np.int32)
	for i in range(len(line)) :
		if line[i] == '+' : n_line[i]=1
		else : n_line[i] = 0

	checked = check(n_line)
	ans = 0
	while checked >= 0 :
		ans += 1
		n_line = flip(n_line, checked)
		checked = check(n_line)
	write.write(str(ans)+'\n')
