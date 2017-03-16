import sys

f = sys.stdin

def readline():
	l = f.readline().strip()
	return l

from bisect import bisect_left

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

		if ChosenNaomi > ken[-1]:
			war += 1
			ken = ken[1:]
		else:
			j = bisect_left(ken, ChosenNaomi)
			ken = ken[0:j] + ken[j+1:]

	return war

def read_game(game_num):
	count = int(readline())
	naomi = map(float, readline().split(" "))
	ken = map(float, readline().split(" "))
	naomi = sorted(naomi)
	ken = sorted(ken)

	deceitful = play_deceitful(count, naomi, ken)
	war = play_war(count, naomi, ken)
	

	print "Case #%d: %d %d" % (game_num, deceitful, war)

def main():
	game_count = int(f.readline())
	for i in range(1, game_count + 1):
		read_game(i)

main()