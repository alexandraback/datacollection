#inp = open ('1t.txt')
#out = open ('1to.txt','w')
inp = open ('1s1.txt')
out = open ('1so1.txt','w')
WIDTH = 4

class Board:
	def __init__(self, data):	
		self.data = data
		self.width = WIDTH
		self.full = True
		self.winner = ''
		
	def checkLine(self, line):
		if self.winner:
			return
			
		x = o = f = True

		for i in line:
			if i == 'X':
				o = False
			if i == 'O':
				x = False
			if i == '.':
				f = o = x = False
		if o:
			self.winner = 'o'
		if x:
			self.winner = 'x'
		if not f:
			self.full = False
		#print line, self.winner

	def checkBoard(self):
	 	f = True
		x = o = False
	
		for row in self.data:
			self.checkLine(row)
			if self.winner:
				return
		
		for i in range(0,WIDTH):
			col = ''
			for j in range(0, WIDTH):
				col += self.data[j][i]
			self.checkLine(col)
			if self.winner:
				return
				
		dg1 = dg2 = ''
		for j in range(0, WIDTH):
			dg1 += self.data[WIDTH-j-1][j]
			dg2 += self.data[j][j]
		self.checkLine(dg1)
		if self.winner:
			return
		self.checkLine(dg2)
		if self.winner:
			return
	
	def stringify(self):
		if self.winner == 'x':
			return 'X won'
		elif self.winner == 'o':
			return 'O won'
		elif self.full:
			return 'Draw'
		else:
			return 'Game has not completed'
			
count = 0
while inp.readline():
	#data
	data = ['']*WIDTH
	data[0] = inp.readline()
	data[1] = inp.readline()
	data[2] = inp.readline()
	data[3] = inp.readline()
	if not data[3]:
		break
	#check
	board = Board(data)
	board.checkBoard()
	count += 1
	result = 'Case #' + str(count) + ': ' + board.stringify()
	print result
	out.write(result+'\n')
inp.close()
out.close()
	
	
	
	