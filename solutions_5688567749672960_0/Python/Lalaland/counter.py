import heapq

in_file = open("in.txt")

test_cases = int(in_file.readline())


def get_num_moves(num_to_reach):

	starting_position = 1

	current_set = [starting_position]
	next_item_count = 1

	seen = set()

	while True:

		next_set = []

		for next_item_num in current_set:

			if next_item_num == num_to_reach:
				return next_item_count

			if next_item_num not in seen:
				seen.add(next_item_num)

				next_set.append(next_item_num+1)
				next_set.append(int(str(next_item_num)[::-1]))

		current_set = next_set
		next_item_count+=1

for case in range(test_cases):
	num_to_reach = int(in_file.readline())
	min_moves = get_num_moves(num_to_reach)

	print("Case #{}: {}".format(case+1,min_moves))

