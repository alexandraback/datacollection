def solve(r, c, w):
	r = int(r)
	c = int(c)
	w = int(w)
	if c% w == 0:
		return int(r * c/w + w-1)
	else:
		return int((r * ((c // w))) + w)
def file_len(fname):
    with open(fname) as f:
        for i, l in enumerate(f):
            pass
    return i + 1
len_file = file_len('sexy_text.txt')


getdata = open('sexy_text.txt')
getdata.readline().strip()


def make_list():
	long_list = []
	for i in range(len_file -1):
		line = getdata.readline().strip()
		line = line.split(" ")
		long_list.append(line)
	return long_list
long_list = make_list()

for i in range(len(long_list)):
	line = solve(long_list[i][0], long_list[i][1], long_list[i][2])
	print("Case #{0}: {1}".format(i+1, line))