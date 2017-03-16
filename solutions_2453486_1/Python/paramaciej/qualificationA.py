#!/usr/bin/env python

def win(x):
	q = {}
	q['X'] = 0
	q['O'] = 0
	q['T'] = 0
	q['.'] = 0
	for i in x:
		q[i] += 1
	if q['X'] + q['T'] == 4:
		return 'X'
	if q['O'] + q['T'] == 4:
		return 'O'
	return 'Nobody'


n = input()
for case in range(1,n+1):
	game = []
	for i in range(4):
		x = raw_input()
		game.append(x)
	raw_input()
	qdots = 0
	for x in game:
		for y in x:
			if y == '.':
				qdots += 1
	for x in range(4):
		sth = ''
		for y in range(4):
			sth += game[y][x]
		game.append(sth)

	game.append(game[0][0]+game[1][1]+game[2][2]+game[3][3])
	game.append(game[0][3]+game[1][2]+game[2][1]+game[3][0])

	andthewinneris = 'Nobody'
	for x in game:
		tempwin = win(x)
		if tempwin != 'Nobody':
			andthewinneris = tempwin
			break
	print "Case #{}: ".format(case),
	if andthewinneris == 'Nobody':
		if qdots:
			print "Game has not completed"
		else:
			print "Draw"
	else:
		print "{} won".format(andthewinneris)

