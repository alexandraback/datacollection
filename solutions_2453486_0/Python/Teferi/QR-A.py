#Tic-Tac-Toe-Tomek
n=input()
for i in range(n) :
	print "Case #%d:"%(i+1),
	l=raw_input()+raw_input()+raw_input()+raw_input()
	raw_input()

	ss=[l[0:16:5],l[3:15:3]]
	ss+=[ l[i*4:i*4+4] for i in range(4) ]
	ss+=[ l[i:16:4] for i in range(4) ]
	
	winner=""
	for s in ss :
		if '.' in s : continue
		if not ('X' in s) : 
			winner="O"
		if not ('O' in s) :
			winner="X"
	if winner :
		print winner+" won"
	elif '.' in l :
		print "Game has not completed"
	else :
		print "Draw"
