import sys, math

# Second largest number in a list -- from http://stackoverflow.com/questions/16225677/get-the-second-largest-number-in-a-list-in-linear-time
def second_largest(numbers):
    first, second = 0, 0
    for n in numbers:
        if n > first:
            first, second = n, first
        elif first > n > second:
            second = n
    return second

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		D = int(fin.readline().strip())
		P_list = [int(x) for x in fin.readline().split()]

		print "Case #%d: " % (t+1)
		print P_list
		split_list = [0 for i in range(D)]
		# null hyp: Don't do anything
		P_list.sort()

		nullHyp = max(P_list)
		minTime = max(P_list)
		for i in range(nullHyp):
			maxP_list = [0] * D
			for i in range(len(P_list)):
				maxP_list[i] = int(math.ceil(float(P_list[i])/(split_list[i]+1)))
			print maxP_list
			maxP = max(maxP_list)
			print "maxP_list: %d" % (maxP)
			index = maxP_list.index(maxP)
			split_list[index] += 1

			# Update the new MaxP
			for i in range(len(P_list)):
				maxP_list[i] = int(math.ceil(float(P_list[i])/(split_list[i]+1)))
			maxP = max(maxP_list)
			new_minTime = sum(split_list) + maxP
			print "new minTime: %d" % new_minTime
			if new_minTime < minTime:
				minTime = new_minTime

		answer = min(nullHyp, minTime)
		print "Answer: %d\n" % answer
		fout.write("Case #%d: %d\n" % (t+1, answer))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	main(fin, fout)
