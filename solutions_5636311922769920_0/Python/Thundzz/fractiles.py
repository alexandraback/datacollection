import sys

def is_possible(nb_tiles, complexity, students):
	return complexity*students >= nb_tiles

def to_base(digitlist, base):
	if(base == 1):
		return len(digitlist)
	else:
		return reduce(lambda x,y:base*x + y, [d for d in digitlist])


def get_indices(nb_tiles, complexity, students):
	if(nb_tiles == 1):
		return [1]
	chosen_indices = []
	current_digit = 0
	for student in range(students):
		current_index = []
		for digit in range(complexity):
			current_index.append(current_digit)
			current_digit += 1
			current_digit = current_digit % nb_tiles
		chosen_indices.append(to_base(current_index, nb_tiles)+1)
	return set(chosen_indices)


def main():
	t = int(sys.stdin.readline().strip())
	for i in range(1,t+1):
		[nb_tiles, complexity,students] = map(int, sys.stdin.readline().strip().split())
		if is_possible(nb_tiles, complexity, students):
			print "Case #%d:" % i, 
			for index in get_indices(nb_tiles, complexity, students):
				print index,
			print ""
		else:
			print "Case #%d: IMPOSSIBLE" % i



if __name__ == '__main__':
	main()
		
