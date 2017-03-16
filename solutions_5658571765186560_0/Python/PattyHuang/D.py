import sys
N=0
cnt=0
for line in sys.stdin:
	if N == 0:
		N = int(line.split("\n")[0])
	else:
		G_check=0
		R_check=0
		cnt += 1
		X = int(line.split("\n")[0].split(' ')[0])
		R = int(line.split("\n")[0].split(' ')[1])
		C = int(line.split("\n")[0].split(' ')[2])
		if R*C % X != 0:
			print "Case #{0}: {1}".format(str(cnt), 'RICHARD')
		else:
			for i in range(1,X+1):
				if X % i == 0:
					length = X/i
				else:
					length = X/i + 1
				width = i
				error = X - length*width
				if (min(R,C)/min(width,length) <= 0):
					R_check += 1
				if (R*C - length*width) < length*width and error < -1:
					R_check += 1
			if R_check > 0:
				print "Case #{0}: {1}".format(str(cnt), 'RICHARD')
			else:
				print "Case #{0}: {1}".format(str(cnt), 'GABRIEL')