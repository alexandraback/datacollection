import sys

f = sys.stdin

def readline():
	l = f.readline().strip()
	return l

def play_deceitful(count, naomi, ken):
	deceitful = 0

	for i in range(0, count):
		if naomi[-1] > ken[-1]:
			deceitful += 1
			naomi = naomi[:-1]
		else:
			naomi = naomi[1:]

		ken = ken[:-1]

	return deceitful

def play_war(count, naomi, ken):
	war = 0

	for i in range(0, count):
		ChosenNaomi = naomi[i]

		ken_win = False
		for j in range(0, len(ken)):
			if ken[j] > ChosenNaomi:
				ken_win = True
				ken = ken[0:j] + ken[j+1:]
				break

		if not ken_win:
			war += 1
			ken = ken[1:]

	return war

def read_game(game_num):
	count = int(readline())
	naomi = map(float, readline().split(" "))
	ken = map(float, readline().split(" "))
	naomi = sorted(naomi)
	ken = sorted(ken)

	war = play_war(count, naomi, ken)
	deceitful = play_deceitful(count, naomi, ken)

	print "Case #%d: %d %d" % (game_num, deceitful, war)

def main():
	game_count = int(f.readline())
	for i in range(1, game_count + 1):
		read_game(i)

main()