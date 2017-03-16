import sys

f = sys.stdin

def readline():
	l = f.readline().strip()
	# print l
	return l

game_num = 0

def read_game():
	global game_num
	C, F, X = map(float, readline().split(" "))

	game_num = game_num + 1

	speed = 2.0

	total = 0.0
	while ((C / speed) + X / (speed + F)) < (X / speed):
		total += C / speed
		speed += F

	total += X / speed

	print "Case #%d: %.7f" % (game_num, total)

def main():
	game_count = int(f.readline())
	for i in range(1, game_count + 1):
		read_game()

main()