import math
import time, itertools

#inp = open ('3s.txt')
#out = open ('3so.txt','w')
inp = open ('3l.txt')
out = open ('3lo.txt','w')
						
count = 0
inp.readline()
ran = inp.readline()
tStart = time.time()

while ran:
	ran = ran.split(' ')
	floor = int(ran[0])
	ceil = int(ran[1])
	
	total = 0
	preCalculate = [0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004]
	
	for x in preCalculate:
		if x >= floor and x <= ceil:
			total += 1
	
	count += 1
	result = 'Case #' + str(count) + ': ' + str(total)
	print result
	out.write(result+'\n')
	ran = inp.readline()
	
inp.close()
out.close()
tStop = time.time()

print(tStop - tStart)/count
	
	
	