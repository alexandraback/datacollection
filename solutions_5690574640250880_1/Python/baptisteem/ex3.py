
def solution_possible(li, col, nb_mines):
	taille = li*col
	if nb_mines >= taille or taille <= 0:
		return False
	nb_blancs = taille - nb_mines
	if nb_blancs == 1:
		return True
	if li == 1 or col == 1: 
		return True
	if li == 2 or col == 2:
		if nb_blancs % 2 == 0 and nb_blancs != 2:
			return True
		return False
	if nb_blancs == 7 or nb_blancs == 5 or nb_blancs == 3 or nb_blancs == 2:
		return False	
	return True

def decompose(nb):
	deux = 0
	trois = 0
	if nb%3 == 1:
		trois = (nb//3-1)
	else:
		trois = nb//3
	deux = (nb - 3*trois)/2
	return deux, trois

def sol_to_str(li, col, sol):
	s = ""
	for i in xrange(li-1):
		for j in xrange(col):
			s = s + str(sol[i][j])
		s = s + '\n'
	for j in xrange(col):
		s = s + sol[li-1][j]
	return s

def solution(li, col, nb_mines):
	sol = [["." for col2 in range(col)] for row in range(li)]
	taille = li * col
	
#	for i in xrange(li):
#		for j in xrange(col):
#			sol[i][j] = "."
#	sol[li-1][col-1] = 'c'
       
	if taille - nb_mines ==1:
		for i in xrange(li):
			for j in xrange(col):
				sol[i][j] = '*'
		sol[li-1][col-1] = 'c'
		return sol
	if li == 1:
		for i in xrange(nb_mines):
			sol[li-1][i] = '*'
		for i in xrange(col-nb_mines):
			sol[li-1][nb_mines+i] = '.'
		sol[li-1][col-1] = 'c'
		return sol
	if col == 1:
		for i in xrange(nb_mines):
			sol[i][col-1] = '*'
		for i in xrange(li-nb_mines):
			sol[nb_mines+i][col-1] = '.'
		sol[li-1][col-1] = 'c'
		return sol
	if li == 2:
		for i in xrange(nb_mines/2):
			sol[0][i] = '*'
			sol[1][i] = '*'
		for i in xrange(col-nb_mines/2):
			sol[0][nb_mines/2+i] = '.'
			sol[1][nb_mines/2+i] = '.'
		sol[li-1][col-1] = 'c'
		return sol
	if col == 2:
		for i in xrange(nb_mines/2):
			sol[i][0] = '*'
			sol[i][1] = '*'
		for i in xrange(li-nb_mines/2):
			sol[nb_mines/2+i][0] = '.'
			sol[nb_mines/2+i][1] = '.'
		sol[li-1][col-1] = 'c'
		return sol
	if nb_mines <= (li-3)*col:
		for i in xrange(nb_mines//col):
			for j in xrange(col):
				sol[i][j] = '*'
		for i in xrange(nb_mines%col):
			sol[nb_mines//col][i] = '*'
		if nb_mines%col+1 == col:
			sol[nb_mines//col][col-2] = '.'
			sol[nb_mines//col+1][0] = "*"
		sol[li-1][col-1] = 'c'
		return sol
	
	deux,trois = decompose(li*col-nb_mines)	
	sol = [["*" for col2 in range(col)] for row in range(li)]
	for i in xrange(trois):
		for j in xrange(3):
			sol[j][i] = '.'
	for i in xrange(deux):
		for j in xrange(2):
			sol[j][i+trois] = '.'
	sol[0][0] = 'c'
	return sol	

nb_case = raw_input()

solutions = []

for i in xrange(int(nb_case)):
	tmp = raw_input()
	tmp = map(int, tmp.split())
	print("Case #%d:" % (i+1))
	if not solution_possible(int(tmp[0]), int(tmp[1]), int(tmp[2])):
		print("Impossible")
	else:
		print(sol_to_str(int(tmp[0]), int(tmp[1]), solution(int(tmp[0]), int(tmp[1]), int(tmp[2]))))
	
