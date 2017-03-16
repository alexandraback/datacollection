def count_n_dig(num):
	# "12345678"
	s_num = str(num)
	dig_num = len(s_num)
	bottom_half = int(s_num[dig_num/2:])
	top_half = int(s_num[:dig_num/2][::-1])
	if top_half == 1:
		return bottom_half
	return top_half + bottom_half

def count(num):
	if num < 10:
		return num
	if num % 10 == 0:
		return count(num-1) + 1
	ret = 10
	p = 10
	while p*10 <= num:
		ret += count_n_dig(p*10 - 1) + 1
		p *= 10
	ret += count_n_dig(num)
	return ret


def parse(filename):
	output = open("output.txt", "w")
	with open(filename, "rb") as f:
		T = int(f.readline())
		for i in xrange(T):
			num = int(f.readline())
			res = count(num)
			output.write("Case #%d: %d\n" % (i+1, res))

parse("input.txt")