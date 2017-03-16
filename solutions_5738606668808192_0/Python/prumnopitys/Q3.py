import numpy as np

class Q3:
	N = 0
	J = 0
	currentNo = 0
	exps = 0
	j = 0

	def __init__(self, N_, J_):
		self.N = N_
		self.J = J_
		self.currentNo = np.zeros(N_)
		self.currentNo[0] = 1
		self.currentNo[N_-1] = 1
		self.exps = np.arange(0, N_) ##We're bigendian it seems

	def doTry(self):
		while self.j < self.J:
			ret, factors = self.factorNumber()

			if ret:
				#srotcaf = factors[::-1]
				nn = str(self.currentNo)
				nn = nn.replace('.','')
				nn = nn.replace(' ','')
				nn = nn.replace(']','')
				nn = nn.replace('[','')
				nn = nn[::-1]
				self.j = self.j+1
				verdict = ''.join((nn,' ',str(factors)))
				verdict = verdict.replace('[','')
				verdict = verdict.replace(']','')
				verdict = verdict.replace(',','')
				print(verdict)
			self.incNumber()

	def factorNumber(self):
		##bases are 2...10
		Results = []
		A = np.ones(self.N)
		success = False
		for b in range(2,11):
			B = b*A
			n = np.sum(self.currentNo*B**self.exps, dtype=np.uint64)
			X = np.int(np.floor(np.sqrt(n)))
			m = 3
			for m in range(3, X+1, 2): ## We are given that the numbers exist
				if m % 5 ==0:
					continue
				o = n % m
				if o == 0:
					Results.append(m)
					success = True
					break
			if success == False:
				return success, -1
			success = False
		return True, Results


	def incNumber(self): ## We know enough numbers exist
		a = 1;
		while True:
			if self.currentNo[a] == 1:
				self.currentNo[a] = 0
				a = a+1
			elif self.currentNo[a] == 0:
				self.currentNo[a] = 1
				break


if __name__ == '__main__':
	q3 = Q3(16, 50)
#	q3 = Q3(6,3)

	print('Case #1:')
	q3.doTry()
