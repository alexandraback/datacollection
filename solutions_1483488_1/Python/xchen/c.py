import sys

def common_init():
	global sout
	sout = sys.stdout.write


def inputing():
	global aa,bb
	line = raw_input();line = line.split();
	aa = int(line[0]);bb = int(line[1]);

place = []
temp = 1;
for i in range (8):
	place.append( temp )
	temp *= 10

def change(x,length,pos):
	big = x / place[pos]
	little = x % place[pos]
	#check leading zero
	if little < place[pos-1]:
		return -1
	return little*place[length - pos] + big

def change2(x,length,pos):
	x = str(x)
	temp = length - pos
	big = x[0:temp]
	little = x[temp:length]
	#print big,little #debug
	return int(little+big)

def work():
	global result
	result = 0;
	for i in range(aa,bb+1):
		length = len(str(i))
		l0 = list()
		for pos in range(1,length):
			t2 = change(i,length,pos)
			if -1 != t2 and aa <= i and i < t2 and t2 <= bb:
				if not t2 in l0:
					l0.append(t2)
					result += 1
	print result

def main():
	n = raw_input()
	n = int(n)
	for i in range(n):
		inputing()
		sout("Case #")
		sout(str(i+1))
		sout(": ")
		work()


common_init()
main()

