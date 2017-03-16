def Check(line):
	if line.count('X')+line.count('T')==4: return 'X'
	elif line.count('O')+line.count('T')==4: return 'O'
	return None
	

def Win(board):
	for i in xrange(0,13,4):
		winner = Check(board[i:i+4])
		if winner != None: return winner

	for i in xrange(0,4):
		winner = Check(board[i]+board[i+4]+board[i+8]+board[i+12])
		if winner != None: return winner
		
	winner = Check(board[0]+board[5]+board[10]+board[15])
	if winner != None: return winner
	winner = Check(board[3]+board[6]+board[9]+board[12])
	if winner != None: return winner
	
	return None
	
	
if __name__ == "__main__":

	fin = open('A-large.in', 'r').readlines()
	fout = open('A-large.out', 'wb')
	T = int(fin[0].strip())

	for i in xrange(T):
		board = fin[5*i+1].strip() + fin[5*i+2].strip() + fin[5*i+3].strip() + fin[5*i+4].strip()
		empty = board.count('.')
		winner = Win(board)
		if winner!=None: fout.write('Case #{}: {} won\n'.format(i+1,winner))
		elif empty>0: fout.write('Case #{}: Game has not completed\n'.format(i+1))
		else: fout.write('Case #{}: Draw\n'.format(i+1))
	