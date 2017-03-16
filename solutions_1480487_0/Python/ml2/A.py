def get_min_vote(val, sorted_s, total_vote):
	min_vote = total_vote
	cur_val = val + total_vote
	num_esses = len(sorted_s)
	not_done = 1
	idx = 0
	while idx < num_esses:
		num = idx + 1
		cur_s = sorted_s[idx]
		if(idx == num_esses - 1):
			min_vote = min_vote - ((cur_val - cur_s) * num / (num + 1))
			break
		next_s = sorted_s[idx+1]
		if(cur_val < cur_s):
			break
		if(cur_val <= next_s):
			min_vote = min_vote - ((cur_val - cur_s) * num / (num + 1))
			break
		diff = (next_s - cur_s)*float(num)
		if(cur_val - diff >= next_s):
			cur_val = cur_val - diff
			min_vote = min_vote - diff
		else:
			min_vote = min_vote - (((cur_val - next_s) + (diff/float(num))) * num / (num + 1))
			break
		idx = idx+1
	if(min_vote <= 0.0):
		return 0.0
	return float(min_vote)/float(total_vote)

fileprefix = 'a-small-3'
reader = open(fileprefix+'.in', 'r')
writer = open(fileprefix+'.out', 'w')
num_cases = int(reader.readline())
for input_number in xrange(1, num_cases+1):
	vals = [float(num) for num in reader.readline().split()]
	N = int(vals[0])
	esses = vals[1:]
	total_vote = float(sum(esses))
	sorted_s = sorted(esses)
	min_vote = {}
	for idx in xrange(N):
		val = sorted_s.pop(idx)
		min_vote[int(val)] = get_min_vote(val, sorted_s, total_vote)
		sorted_s.insert(idx,val)
	output = ''
	for val in esses:
		output += ' '+str(min_vote[int(val)]*100)
	writer.write('Case #'+str(input_number)+":"+str(output)+'\n')
	
