def rank_and_file(str_list):
	height_counts = {}
	for row in str_list:
		heights = row.split(' ')
		for height in heights:
			if height not in height_counts.keys():
				height_counts[height] = 1
			else:
				height_counts[height] += 1
	missing_heights = []
	for height in height_counts.keys():
		if height_counts[height] % 2 != 0:
			missing_heights.append(height)
	missing_heights = map(int, missing_heights)
	missing_heights.sort()		
	missing_heights = map(str, missing_heights)
	return ' '.join(missing_heights)

def formatted_output(index, final_count):
    return 'Case #' + str(index) + ': ' + str(final_count)


t = int(raw_input())  
for i in range(1, t + 1):
    m = int(raw_input())
    n = []
    for j in range(2*m-1):
    	line = raw_input()
    	n.append(line)
    print formatted_output(i, rank_and_file(n))