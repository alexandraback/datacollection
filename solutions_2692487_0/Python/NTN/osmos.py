def getline():
	return [int(i) for i in input().split()]

def get_moves(b):
	moves = 0
	summa = size
	for i in range(len(koot)-b):
		while summa <= koot[i]:
			moves += 1
			summa += summa - 1
		summa += koot[i]

	return moves

def case():
	global koot, size
	size, _ = getline()

	koot = getline()
	koot.sort()

	if size <= 1:
		print(len(koot))
		return

	print(min(get_moves(i) + i for i in range(0, len(koot)+1)))


for i in range(1, int(input())+1):
	print('Case #%i: ' % i, end='')
	case()