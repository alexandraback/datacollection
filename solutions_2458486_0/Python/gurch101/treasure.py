from collections import Counter
 
def get_num_keys_in_chest(chest, my_keys, key_used):
	num_keys = 0
	if key_used in chest['keys']:
		num_keys = num_keys + 1
	for k in chest['keys']:
		if k not in my_keys:
			num_keys = num_keys + 1
	return num_keys
	
num_test_cases = int(raw_input()) + 1

for i in xrange(1, num_test_cases):
	num_keys, num_chests = [int(x) for x in raw_input().split()]
	my_keys = Counter([int(x) for x in raw_input().split()])
	chests = {}
		
	for chest_num in xrange(1, num_chests + 1):
		chest_details = [int(x) for x in raw_input().split()]
		key_to_open = chest_details[0]
		num_keys_in_chest = chest_details[1]
		keys = chest_details[2:]

		if key_to_open not in chests:
			chests[key_to_open] = {}
		
		chests[key_to_open][chest_num] = {'keys':keys}

	"""
		open the chest that gives the most usable keys
		in the case of a tie, open the chest with the lowest index
	"""
	chest_open_seq = []
	while num_chests > 0:
		chest_to_open = -1
		key_used = -1
		new_keys = []
		solo_chest = False
		for key in my_keys:
			if key in chests:
				# the key only opens one chest
				if len(chests[key].items()) == 1 and (chest_to_open == -1 or chests[key].items()[0][0] < chest_to_open):
					chest_to_open = chests[key].items()[0][0]
					key_used = key
					new_keys = chests[key][chest_to_open]['keys']
					solo_chest = True
					
				for chest_num, chest in chests[key].items():
					num_keys_in_chest = get_num_keys_in_chest(chest, my_keys, key)
					if num_keys_in_chest > len(new_keys):
						if solo_chest == False or chest_to_open > chest_num:
							key_used = key
							chest_to_open = chest_num
							new_keys = chest['keys']
					elif num_keys_in_chest == len(new_keys) and (chest_num < chest_to_open or chest_to_open == -1):
						chest_to_open = chest_num
						new_keys = chest['keys']
						key_used = key
		
		if key_used == -1:
			outcome = "IMPOSSIBLE"
			break
			
		del chests[key_used][chest_to_open]
		my_keys[key_used] = my_keys[key_used] - 1
		
		if my_keys[key_used] <= 0:
			del my_keys[key_used]
		
		for k in new_keys:
			if k in my_keys:
				my_keys[k] = my_keys[k] + 1
			else:
				my_keys[k] = 1
		num_chests = num_chests - 1
		chest_open_seq.append(chest_to_open)
		
		if len(my_keys) == 0:
			outcome = "IMPOSSIBLE"
			break
			
	seq = ''
	seq = ' '.join([str(x) for x in chest_open_seq])
	if seq == '':
		seq = outcome
		
	print "Case #%s: %s" % (i, seq)
					