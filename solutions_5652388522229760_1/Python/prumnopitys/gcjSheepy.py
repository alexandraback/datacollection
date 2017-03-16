import numpy as np
import pandas as pd

class gcjSheepy:
	noTrials = -1
	lastNumbers = 0
	reader = 0

	def __init__(self, filePath):
		self.reader = pd.read_table(filePath, iterator = True, header=None)
		a = self.reader.get_chunk(1)
		self.noTrials = a.iat[0,0]

	def maaiinn(self):
		for j in range(1, self.noTrials+1):
			res = self.getLastMulty()

			print('Case #', str(j), ': ', res, sep='')
	
	def getLastMulty(self):
		a = self.reader.get_chunk(1)
		x = a.iat[0,0]
		#print(x)

		if x == '':
			return ''

		if x == 0:
			return 'INSOMNIA'
		
		n = 1
		l = x*n

		S = pd.Index([int(i) for i in str(l)])
		S = S.drop_duplicates()

		if S.size == 10:
			return l

		while True:
			n=n+1
			l = n*x
			S = S.union([int(i) for i in str(l)])
			S = S.drop_duplicates()
			if S.size == 10:
				return l



if __name__ == '__main__':
	path = 'A-large (1).in'
	sheepy = gcjSheepy(path)
	sheepy.maaiinn()

