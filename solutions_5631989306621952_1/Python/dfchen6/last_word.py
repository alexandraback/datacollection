def last_word(s):
	result = "" + s[0]
	for i in range(1, len(s)):
		curr = s[i]
		if curr >= result[0]:
			result = curr + result
		else:
			result = result + curr
	return result

if __name__ == "__main__":
    f = open('A-large.in', 'r')
    output = open('A-large.out', 'w')
    C = int(f.readline())
    for i in range(0, C):
        s = f.readline()
        output.write("Case #" + str(i + 1) + ": " + str(last_word(s)))
