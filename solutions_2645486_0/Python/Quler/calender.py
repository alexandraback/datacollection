#Python
def process(M, R, N, gains, start, remain):
	#print "inside: " + str(start) + "," + str(remain)
	if start == N or remain <= 0:
		return 0
	if remain > M:
		remain = M
	if start == N-1:
		return remain*gains[start];
	result = 0
	for i in range(remain+1):
		tmp = i*gains[start] + process(M, R, N, gains, start+1, remain-i+R)
		if tmp > result:
			#print "tmp: " + str(tmp)
			result = tmp
	return result

fn = open('B-small-attempt0.in','r')
T = int(fn.readline())
for i in range(T):
	line = fn.readline()
	vals = line.split(' ')
	M = int(vals[0])
	R = int(vals[1])
	N = int(vals[2])
	line = fn.readline()
	vals = line.split(' ')
	gains = []
	for j in range(N):
		gains.append(int(vals[j]))
	
	r = process(M, R, N, gains, 0, M)

	print "Case #" + str(i+1) + ": " + str(r)
