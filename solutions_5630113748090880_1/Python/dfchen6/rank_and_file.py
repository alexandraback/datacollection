def get_line(mydict):
	line = []
	for key, value in mydict.iteritems():
		if value % 2 == 1:
			line.append(key)
	line.sort()
	last_line = ' '.join(str(i) for i in line)
	return last_line

if __name__ == "__main__":
    f = open('B-large.in', 'r')
    output = open('B-large.out', 'w')
    C = int(f.readline())
    for i in range(0, C):
        N = int(f.readline())
        mydict = dict()
        for j in range(0, 2 * N - 1):
        	line = f.readline()
        	for num in line.split(' '):
        		if int(num) not in mydict:
        			mydict[int(num)] = 1
        		else:
        			mydict[int(num)] = mydict[int(num)] + 1
        last_line = get_line(mydict)
        output.write("Case #" + str(i + 1) + ": " + last_line + "\n")