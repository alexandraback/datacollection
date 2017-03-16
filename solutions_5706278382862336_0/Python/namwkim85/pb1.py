import sys
import math
import itertools
import fractions
import copy
def is_power2(num):
	return num != 0 and ((num & (num - 1)) == 0)
def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())

	for t in range(T):
		#print 'test: ', t
		PQ = f.readline().strip().split('/')
		P = int(PQ[0])
		Q = int(PQ[1])
		div = fractions.gcd(P, Q)
		P /=div
		Q /=div

		success = False
		gen = 0
		while(Q>0):
			#print P, Q
			a = P/Q
			#print 'a: ', a
			#b = P%Q
			if a>=1:
				success = True
				break

			if is_power2(Q)==False:
				print Q, 'break'
				break
			if gen>40:
				break
			Q=Q/2
			gen += 1
		if success:
			of.write('Case #'+str(t+1)+': '+str(gen)+'\n')
			print 'Case #'+str(t+1)+': '+str(gen)			
		else:
			of.write('Case #'+str(t+1)+': impossible\n')
			print 'Case #'+str(t+1)+': impossible'			

	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

