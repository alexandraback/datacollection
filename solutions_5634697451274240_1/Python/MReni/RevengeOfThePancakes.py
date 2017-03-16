import math
import collections

HAPPY_PANCAKE = '+'
UNHAPPY_PANCAKE = '-'

# pancake_min_flips = None
# pancake_map = {} # {pancake: {value: value, parents}}
pancake_value_map = {} #{pancake: steps to final}
pancake_parent_map = {} #{pancake: [parent1, parent2]}
super_parent = ""

def all_happy(pancakes):
	return (UNHAPPY_PANCAKE not in pancakes)

def flip(pancakes, count):
	flipped_pancakes = ''
	for i in range(0, count):
		this_pancake = HAPPY_PANCAKE if pancakes[i] == UNHAPPY_PANCAKE else UNHAPPY_PANCAKE
		flipped_pancakes = flipped_pancakes + this_pancake
	return flipped_pancakes[::-1] + pancakes[count:]

# def get_min_flips(pancakes, current_flips):
# 	if all_happy(pancakes):
# 		if not pancake_min_flips or pancake_min_flips > current_flips:
# 			pancake_min_flips = current_flips
# 		return current_flips

# 	min_flips = None
# 	while not all_happy(pancakes):
# 		for i in range(0, len(pancakes)):
# 			flipped_pancakes = flip(pancakes, i)
# 			current_flips = current_flips + 1
# 			if pancake_min_flips and current_flips > pancake_min_flips:
# 				continue

# 			# If we have seen this map and with smaller flips, use smaller flips
# 			if flipped_pancakes in pancake_map:
# 			  	if pancake_map[flipped_pancakes] > current_flips:
# 				final_flips = current_flips + pancake_map[flipped_pancakes]
# 			else:
# 				final_flips = get_min_flips(flipped_pancakes, current_flips)
# 				if current_min_flips and current_min_flips < final_flips:
# 					return current_flips

# 			if not min_flips or current_flips < min_flips :
# 				min_flips = current_flips
# 	return min_flips

# def get_min_flips(pancakes, depth):
# 	if all_happy(pancakes):
# 		# print "all happy"
# 		return 0

# 	if pancakes in pancake_map:
# 		return pancake_map[pancakes]

# 	current_min_flips = None
# 	for i in range(1, len(pancakes)+1):
# 		flipped_pancakes = flip(pancakes, i)
# 		# print "This is my local " + str(i) + " flip from " + pancakes + " to " + flipped_pancakes
# 		# print pancake_map
# 		if flipped_pancakes not in attempts or attempts[flipped_pancakes] > depth:
# 			attempts[flipped_pancakes] = depth
# 			future_min_flips = get_min_flips(flipped_pancakes, depth + 1)
# 			# print "Not in attempts and have a future min flip of " + str(future_min_flips)
# 			# print "Futures: " + str(i) + " :" + str(future_min_flips)
# 			# print "count: " + str(i) + " flipped_pancakes: " + flipped_pancakes + ". future_min_flips: " + str(future_min_flips)
# 			if future_min_flips != None:
# 				my_flip = 1 + future_min_flips
# 				# print "MYFlips: " + str(i) + " :" + str(my_flip)
# 				if pancakes not in pancake_map or pancake_map[pancakes] > my_flip:
# 					pancake_map[pancakes] = my_flip

# 				if current_min_flips == None or current_min_flips > my_flip:
# 					current_min_flips = my_flip
# 	# if current_min_flips != None and (pancakes not in pancake_map or pancake_map[pancakes] > current_min_flips):
# 	# 	pancake_map[pancakes] = current_min_flips
# 	return current_min_flips

def update_all_parents(pancakes, value, previous_value):
	# old_parent_value + (value - previous_value + 1)
	# Previous value either > current value or does not exist or = current value
	if not pancakes:
		return
	for parent in pancake_parent_map[pancakes]:
		old_parent_value = pancake_value_map[parent]
		expected_new_value = (old_parent_value or 0) + (value - (previous_value or 0) + 1)
		if old_parent_value == None or old_parent_value > expected_new_value:
			pancake_value_map[parent] = expected_new_value
			update_all_parents(parent, expected_new_value, old_parent_value)

def find_consecutive_chars(pancakes):
	count = 1
	first_char = pancakes[0]
	for i in range(1, len(pancakes)):
		if pancakes[i] == first_char:
			count = count + 1
		else:
			return count
	return count

def get_min_flips(pancakes, depth):
	if all_happy(pancakes):
		previous_value = pancake_value_map.get(pancakes, None)
		if previous_value == None or previous_value > 0:
			pancake_value_map[pancakes] = 0
			update_all_parents(pancakes, 0, previous_value)
		
		# return 0

	if pancake_value_map.get(pancakes) != None:
		update_all_parents(pancakes, pancake_value_map[pancakes], pancake_value_map[pancakes])

	#find consecutive marks at the beginning:
	min_count = find_consecutive_chars(pancakes)
	for i in range(max(min_count, depth), len(pancakes) + 1):
		flipped_pancakes = flip(pancakes, i)
		if pancakes not in pancake_parent_map[flipped_pancakes] and flipped_pancakes not in pancake_value_map:# and flipped_pancakes != super_parent:
			pancake_value_map[flipped_pancakes] = None
			pancake_parent_map[flipped_pancakes].add(pancakes)
			get_min_flips(flipped_pancakes, i )

count = 1
with open('dataBlarge', 'rb') as data:
	for pancakes in data:
		# pancake_min_flips = None
		# pancake_map[pancakes] = 0
		pancakes = pancakes.replace('\n', '')
		pancake_value_map = {pancakes: None}
		pancake_parent_map = collections.defaultdict(set)
		super_parent = pancakes

		# print "Case #" + str(count) + ": " + str(get_min_flips(pancakes, None))
		try:
			get_min_flips(pancakes, 1)
			print "Case #" + str(count) + ": " + str(pancake_value_map[pancakes])

		except KeyboardInterrupt:
			print "Case #" + str(count) + ": " + str(10)
		# print pancake_value_map
		# print pancake_parent_map
		# find_shortest(pancakes)
		count = count + 1