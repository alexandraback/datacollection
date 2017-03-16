import numpy as np
import pandas as pd

class fractality:
	__K__ = -1
	__S__ = -1
	__C__ = -1
	TREE  = -1
	POSI  = -1
	
	def __init__(self, K, C, S):
		self.__K__ = K
		self.__S__ = S
		#self.__C__ = C
		self.POSI = []
		
		self.TREE = node(K, C)
	
	def placeSpectators(self):
		tilesToPlumb = [i for i in range(self.__K__)]
		branch = self.TREE
		possible=False
		lastPosition=0
		newPosition=0
		
		while self.__S__>0:
			if len(tilesToPlumb):
				t = tilesToPlumb.pop()
			else:
				possible=True
				t = 0
			branch = branch.getNode(t)
			newPosition = lastPosition*self.__K__+t
			lastPosition = 0
			
			if branch is None:
				self.POSI.append(newPosition+1)
				self.__S__ = self.__S__-1
				
				if len(tilesToPlumb) == 0:
					possible=True
					break
				
				branch = self.TREE
				newPosition = 0
				lastPosition = 0
				
				continue
			
			lastPosition = newPosition
		
		#print(possible, ' ', self.POSI)	
		return possible, self.POSI



class node:
	__S__ = -1
	__C__ = -1
	__K__ = -1

	def __init__(self, K, C):
		self.__S__ = pd.Series(index=[i for i in range(K)])
		self.__K__ = K
		self.__C__ = C
	
	def getNode(self, k):
		if self.__C__>1:
			return node(self.__K__,self.__C__-1)
		else:
			return None

if __name__ == '__main__':
	K = 3; C = 3; S = 2;
	reader = pd.read_table('D-large.in', header=None, iterator=True)
	
	line = reader.get_chunk(1)
	n = line.iat[0,0]

	for i in range(1,1+n):
		line = reader.get_chunk(1)
		L = line.get_value(0,0)
		[K, C, S] = L.split()

		fd = fractality(int(K), int(C), int(S))
		ret, A = fd.placeSpectators()

		verdict = ''
		if ret :
			verdict =''.join(('Case #', str(i), ': ', str(A)))
			verdict = verdict.replace('[', '')
			verdict = verdict.replace(']', '')
			verdict = verdict.replace(',', '')
		else:
			verdict =''.join(('Case #', str(i), ': ', 'IMPOSSIBLE'))

		print(verdict)	
