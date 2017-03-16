import sys

dyn = {}

def solve(cars, comb, first_letter):
	comb_string = ""
	car_count = 0
	for i in comb:
		if i:
			comb_string += "1"
			car_count += 1
		else:
			comb_string += "0"

	if car_count == 0:
		return 1

	if comb_string in dyn:
		dyn_comb = dyn[comb_string]
		if first_letter is None:
			if "None" in dyn_comb:
				return dyn_comb["None"]
		else:
			if first_letter in dyn_comb:
				return dyn_comb[first_letter]

	res = 0
	for first_car_index in range(len(cars)):
		if not comb[first_car_index]:
			continue
		first_car = cars[first_car_index]
		if (first_letter is not None) and (first_car[0] != first_letter):
			continue
		letter_set = set()
		last_letter = first_car[len(first_car) - 1]
		valid = True
		last_letter_found = False
		for i in range(len(first_car)):
			if first_car[i] != last_letter:
				if not last_letter_found:
					letter_set.add(first_car[i])
				else:
					valid = False
			else:
				last_letter_found = True
				
		if not valid:
			continue
				
		new_comb = []
		valid = True
		last_letter_found = False
		for car_index in range(len(cars)):
			new_comb.append(comb[car_index])
			if not comb[car_index]:
				continue
			if car_index == first_car_index:
				continue
			car = cars[car_index]
			for letter in letter_set:
				if car.find(letter) != -1:
					valid = False
			if car.find(last_letter) != -1:
				last_letter_found = True
			
		if valid:
			new_comb[first_car_index] = False
			res = (res + solve(cars, new_comb, last_letter if last_letter_found else None)) % 1000000007
			
	if comb_string not in dyn:
		dyn[comb_string] = {}

	if first_letter is None:
		dyn[comb_string]["None"] = res
	else:
		dyn[comb_string][first_letter] = res

	return res

t = int(sys.stdin.readline().strip())

for i in range(t):
	print "Case #" + str(i + 1) + ":",
	n = int(sys.stdin.readline().strip())
	cars = sys.stdin.readline().strip().split()
	dyn = {}
	comb = []
	for j in range(len(cars)):
		comb.append(True)
	print solve(cars, comb, None)

