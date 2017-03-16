import sys

def common_init():
	global sout
	sout = sys.stdout.write


def inputing():
	global n,ns,least
	global array
	line = raw_input()
	line = line.split()
	n = int(line[0])
	ns = int(line[1])
	least = int(line[2])
	array = [0]*n
	for i in range(3,3+n):
		array[i-3] = int(line[i])

def work():
	global result
	global ns
	result = 0
	for i in array:
		remainder = i % 3;
		quotient = i / 3;
		v2 = -1
		if 0 == remainder:
			v1 = quotient
			if i >= 2:
				v2 = quotient + 1
		elif 1 == remainder:
			v1 = quotient + 1
		else :
			v1 = quotient + 1
			if i >= 2:
				v2 = quotient + 2
		#print " i:%d v1 %d   v2 %d  r: %d" % (i, v1,v2,remainder )
		if v1 >= least:
			result += 1
			#print "directly "
		elif v2 >= least and ns > 0:
			result += 1
			ns -= 1
			#print "by +1 "
	print result

def main():
	n = raw_input();
	n = int(n);
	for i in range(n):
		inputing()
		sout("Case #")
		sout(str(i+1))
		sout(": ")
		work()


common_init()
main()

