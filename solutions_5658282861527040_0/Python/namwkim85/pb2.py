import sys
import math
import itertools
import copy

def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())

	for t in range(T):
		n = f.readline().strip().split(' ')
		A = int(n[0])
		B = int(n[1])
		K = int(n[2])

		count = 0
		for i in range(K):
			for j in range(i, A):
				for k in range(i, B):
					if j&k==i:
						count += 1
		of.write('Case #'+str(t+1)+': '+str(count)+'\n')
		print 'Case #'+str(t+1)+': '+str(count)
	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

