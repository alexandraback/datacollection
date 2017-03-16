import sys
import math

E = 0.00001

def equal(a, b):
	if abs(a-b)>E:
		return False
	return True

def main(filename):
	f = open(filename)
	of = open(filename.split('.')[0]+'.out', 'w')
	T = int(f.readline())


	for t in range(T):
		num = int(f.readline().strip())
		n 	= f.readline().strip().split(' ')
		k  	= f.readline().strip().split(' ')
		Naomi = []
		Ken = []
		for i in range(num):
			Naomi.append(float(n[i]))
			Ken.append(float(k[i]))
		
		Naomi.sort()
		Ken.sort()

		winNaomiCnt = 0
		while len(Naomi)>0:
			nidx = len(Naomi)-1;
			Cn = Naomi[nidx]

			Ck  = Ken[0]
			kidx = 0
			for j in range(len(Ken)):
				if Ken[j]>Cn:
					Ck  = Ken[j]
					kidx = j
			if Ck < Cn:
				winNaomiCnt += 1
			del Naomi[nidx]
			del Ken[kidx]

		for i in range(num):
			Naomi.append(float(n[i]))
			Ken.append(float(k[i]))
		
		Naomi.sort()
		Ken.sort()

		saveCnt = winNaomiCnt
		winNaomiCnt = 0
		while len(Naomi)>0:
			nidx = len(Naomi)-1
			kidx = len(Ken)-1

			if Naomi[nidx]>Ken[kidx]:
				winNaomiCnt += 1
				del Naomi[nidx]
				del Ken[kidx]
			else:
				del Naomi[0]
				del Ken[kidx]

		of.write('Case #'+str(t+1) + ': ' + str(winNaomiCnt)+' ' + str(saveCnt) + '\n')

	f.close()
	of.close()

if __name__ == '__main__':
	if len(sys.argv)==1:
		print 'missing a filename'
		exit(1)
	main(sys.argv[1])
	sys.exit(0)

