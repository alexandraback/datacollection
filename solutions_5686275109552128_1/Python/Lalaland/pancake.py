
in_file = open("in.txt")

test_cases = int(in_file.readline())

import math

def num_moves_required_for_time(plate, time):
	return (((plate + time -1)//time) -1)

def can_be_eaten_in_time(plates, total_time, num_moves):
	num_moves_required = sum(num_moves_required_for_time(plate, total_time-num_moves) for plate in plates)

	return num_moves_required <= num_moves

def can_possibly_be_eaten_in_time(plates, total_time):
	num_moves = range(total_time)

	return any(can_be_eaten_in_time(plates,total_time,moves) for moves in num_moves)

def binary_search(a, b, test):
	if a+1 == b:
		return b

	current = (a + b)//2

	if test(current):
		return binary_search(a,current,test)
	else:
		return binary_search(current,b,test)

for case in range(test_cases):
	num_plates = int(in_file.readline())
	plates = [int(a) for a in in_file.readline().strip().split(" ")]

	min_time = binary_search(0,1000,lambda time: can_possibly_be_eaten_in_time(plates,time))

	print("Case #{}: {}".format(case+1,min_time))

