import sys
from itertools import groupby


def squash(pancakes):
	return [group[0] for group in groupby(pancakes)]	

def flip(pancake):
	if(pancake == '+'):
		return '-'
	elif (pancake == '-'):
		return '+'
	else:
		raise Exception('Pancake was neither blank nor flipped happly')

def apply_best_step(pankcakes):
	pankcakes = list(pankcakes)
	if (len(pankcakes) % 2) == 1:
		pankcakes[0] = flip(pankcakes[0])
	else:
		pankcakes[:-1] =  [flip(pankcake) for pankcake in reversed(pankcakes[:-1])]

	return pankcakes

def make_happy(pancakes):
	nb_steps = 0
	pancakes = squash(pancakes)
	while pancakes != ['+']:
		pancakes = squash(apply_best_step(pancakes))
		nb_steps += 1
	return nb_steps


def main():
	t = int(sys.stdin.readline().strip())
	for i in range(1,t+1):
		pancakes = sys.stdin.readline().strip()
		print "Case #%d: %d" % (i, make_happy(pancakes))

if __name__ == '__main__':
	main()