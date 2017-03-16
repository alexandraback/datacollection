import numpy as np
import pandas as pd

class soManyPancakes:
	## This problem is counting the number of groups ending in an upsidedown group.
	reader = 0
	noRows = -1
	def __init__(self, path):
		self.reader = pd.read_table(path, iterator=True, header=None)
		a = self.reader.get_chunk(1)
		self.noRows = a.iat[0,0]
	
	def countOneLine(self):
		linT = self.reader.get_chunk(1)
		line = linT.get_value(0,0)
		
		## Sequential occurences if any of UD, DU, UD ..

		##DU
		DU = line.count('-+')
		UD = line.count('+-')
		#print(line)
		pieces = DU + UD
		if line[-1] != '+':
			pieces = pieces+1
		return pieces


if __name__ == '__main__':
	breakfast = soManyPancakes('B-large.in') ##Wow I am like, really hungry.
	for n in range(1, breakfast.noRows+1):
		m = breakfast.countOneLine()
		print('Case #',n,': ',m,sep='')
