import math
import time, itertools

inp = open ('3t.txt')
out = open ('3to.txt','w')
#inp = open ('3l.txt')
#out = open ('3lo.txt','w')
						
count = 0
inp.readline()
ran = inp.readline()
tStart = time.time()

while ran:
	ran = ran.split(' ')
	floor = int(ran[0])
	ceil = int(ran[1])
	total = 0
	
	#9:3 10:4
	qf = int(math.ceil(floor**0.5))
	#16:4 15:3
	qc = int(ceil**0.5)
	
	composed = '['
	for i in range(qf, qc+1):
		xi = str(i)
		if xi[::-1] != xi:
			continue
		x = str(i**2) #1.2949
		if x[::-1] == x:
			total += 1
			composed += x +','
	composed += ']'
	print composed
	count += 1
	result = 'Case #' + str(count) + ': ' + str(total)
	print result
	out.write(result+'\n')
	ran = inp.readline()
	
inp.close()
out.close()
tStop = time.time()

print(tStop - tStart)/count
	
	
	