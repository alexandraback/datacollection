import math

def get_position(lst, K):
	lst = map(lambda x: x-1, lst)
	result = 0
	l = len(lst)
	for i in range(l):
		result += lst[l-1-i] * (K**i)
	result += 1
	return result

for t in range(int(raw_input())):
	data = map(int, raw_input().split())
	K = data[0]
	C = data[1]
	S = data[2]

	result = ""
	if math.ceil(1.0 * K / C) > S: # number of students required
		result = "IMPOSSIBLE"
	else:
		one_to_K = range(1, K+1)
		par = [one_to_K[i:i+C] for i in xrange(0, K, C)] # partition
		
		result_list = []
		for lst in par:
			result_list.append(get_position(lst, K))

		result_str = str(result_list)
		result = result_str[1:len(result_str)-1].replace(",", "")
	print "Case #%d:" % (t+1), result