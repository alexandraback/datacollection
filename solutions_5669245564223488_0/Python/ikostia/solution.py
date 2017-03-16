#! /usr/bin/python

debug = False
MOD = 1000000007

def rdc(s):
	res = []
	for i in xrange(len(s)):
		c = s[i]
		if i == 0:
			res.append(c)
			continue
		if c == s[i-1]:
			continue
		res.append(c)
	return "".join(res)


def fact(n):
	r = 1
	for i in xrange(1, n + 1):
		r = (r * i) % MOD
	return r


def solve(input_data):
	n, cars = input_data
	all_cars = map(rdc, cars)
	one_cars = sorted([car for car in all_cars if len(car) == 1])
	
	
	res = 1

	# process one_cars
	c = []
	current = 1
	for i in xrange(len(one_cars)):
		if i == 0:
			c.append(one_cars[i])
			current = 1
			continue
		
		if one_cars[i] == one_cars[i - 1]:
			current += 1
			continue

		res = (res * fact(current)) % MOD
		c.append(one_cars[i])
		current = 1

	if current != 1:
		res = (res * fact(current)) % MOD

	one_cars = c

	# check correctness of middle letters
	middles = set([])
	for car in all_cars:
		for c in car[1:-1]:
			if c in middles:
				if debug:
					print "middles problem"
				return "0"
			middles.add(c)

	for car in all_cars:
		if car[0] in middles or car[-1] in middles:
			if debug:
				print "middles problem"
			return "0"


	all_cars = map(lambda car: car[0] + car[-1], all_cars)

	# if one_car is the same as last letter of some car
	# or first letter of some car, concat those
	to_del = []
	for i in xrange(len(one_cars)):
		for j in xrange(len(all_cars)):
			one = one_cars[i]
			car = all_cars[j]

			if car[0] == car[1]:
				continue

			if car[0] == one or car[1] == one:
				to_del.append(i)

	one_cars = [one_cars[i] for i in xrange(len(one_cars)) if i not in to_del]
	all_cars = [car for car in all_cars if car[0] != car[1]]
	permutable = len(one_cars)

	if debug:
		print "one_cars: ", one_cars
		print "all_cars: ", all_cars

	for i in xrange(len(all_cars)):
		if all_cars[i] == None:
			continue

		train = all_cars[i]
		all_cars[i] = None
		fl = train[0]
		ll = train[-1]
		
		found = True
		while found:
			found_first = 0
			found_last = 0
			j = i + 1
			if debug:
				print "Outer while: ", fl, ll
			new_fl, new_ll = "", ""
			while j < len(all_cars):
				car = all_cars[j]
				if car == None:
					j = j + 1
					continue
				if debug:
					print "Inner while: ", car, fl, ll
				if fl == car[-1]:
					train = car + train
					found_first += 1
					new_fl = car[0]
					all_cars[j] = None
				elif ll == car[0]:
					train = train + car
					found_last += 1
					new_ll = car[-1]
					all_cars[j] = None

				j = j + 1

			if found_last > 1 or found_first > 1:
				if debug:
					print "found_last > 1 or found_first > 1: ", found_first, found_last
				return "0"

			if found_first == 0 and found_last == 0:
				found = False

			fl = new_fl if found_first else fl
			ll = new_ll if found_last else ll
			if fl == ll:
				if debug:
					print "fl == ll"
				return "0"

		j = i + 1
		while j < len(all_cars):
			if all_cars[j] == None:
				j = j + 1
				continue

			car = all_cars[j]

			if fl in car or ll in car:
				if debug:
					print "fl in car or ll in car for non-train car" 
				return "0"

			j = j + 1


		permutable += 1
		if debug:
			print "train: ", train
			print "permutable: ", permutable, fact(permutable)
			print "res: ", res

	res = (res * fact(permutable)) % MOD

	if debug:
		print "All are none: ", all(map(lambda c: c == None, all_cars))

	return res % MOD


def read_input():
	n = int(raw_input())
	s = raw_input().split()
	return (n, s)
	
def main():
	T = int(raw_input())
	for t in xrange(T):
		print "Case #%d: %s" % (t + 1, solve(read_input()))

if __name__ == "__main__":
	main()
