import sys

def main():
	f = open(sys.argv[1], 'r');
	T = int(f.readline());
	for i in range(0, T):
		# print i;
		Line1 = f.readline().split();
		A = int(Line1[0]);
		B = int(Line1[1]);
		K = int(Line1[2]);
		N = 0;
		
		for j in range (0, A):
			for k in range (0, B):
				# print j ^ k
				if j & k < K:
					N += 1;
		
		print "Case #%d: %d" % (i + 1, N);
	f.close();

main();