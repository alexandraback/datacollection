import math

def write_to_file(arr):
	result_file = open('output2.txt', 'w')
	for i in range(len(arr)):
		result_file.write("Case #" + str(i + 1) + ": " + str(arr[i])+ '\n') 

def getResult(first, second):

	max_energy = int(first.split(" ")[0])
	regain_amt = int(first.split(" ")[1])
	num_activities = int(first[2])
	second = second.split(" ")
	activity_val = sorted([int(elem) for elem in second])
	activity_val = activity_val[::-1]

	if (max_energy == regain_amt):
		result = get_max_energy_same_gain(max_energy, activity_val)
		return result
	else:
		result = get_max_energy(max_energy, regain_amt, num_activities, activity_val)
		return result

def get_max_energy(energy, regain, total_act, vals):
	result = 0
	for i in range(len(vals)):
		if i == len(vals) - 1:
			result += vals[i] * energy
		else:
			first = vals[i]
			second = vals[i + 1]
			if (first > second):
				result += vals[i] * energy
				energy = regain
			else:
				result += vals[i] * regain
	return result

def get_max_energy_same_gain(num, array_num):
	result = 0;
	for i in array_num:
		result += num * i
	return result

#Main function
if __name__ == "__main__":
	lines = [line.strip() for line in open('input.txt')]
	numTests = lines.pop(0)
	offset = 2
	results = []
	for i in range(0, int(numTests)):
		first = lines[i * 2]
		second = lines[(i * 2) + 1]
		result_one = getResult(first, second)
		results.append(result_one)

	write_to_file(results)



