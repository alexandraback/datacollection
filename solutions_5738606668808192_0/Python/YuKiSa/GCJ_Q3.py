import numpy as np

def generate_bin(length, lev, g_bin) :
	if lev==0 : generate_bin(length, lev+1, [1])
	elif lev<length-1 :
		g_bin.append(0)
		generate_bin(length, lev+1, g_bin)
		g_bin.pop()
		g_bin.append(1)
		generate_bin(length, lev+1, g_bin)
		g_bin.pop()
	else :
		g_bin.append(1)
		for i in range(2) :
			for x in g_bin : write.write(str(x))
		for i in range(2, 11) :
			length = len(g_bin)
			i_sum = 0
			for j in range(length) :
				if g_bin[length-1-j] == 1 : i_sum += pow(i, j)
			write.write(' '+str(i_sum))
		write.write('\n')
		g_bin.pop()
		global done, maxi
		done += 1
		if done >= maxi :
			write.close()
			stop

write = open('output.txt', 'wb')
write.write('Case #1:\n')

n = 16
global done, maxi
maxi = 50
done = 0

generate_bin(8, 0, [])