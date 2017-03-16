def count_flips(stack):
	flips = 0
	if len(stack) == 1:
		return 0
	else:
		index = 1
		for index in range(1, len(stack)):
			if stack[index] != stack[index - 1]:
				flips += 1
	return flips

def check_last(stack):
	if stack[-1] == '-':
		return 1
	else:
		return 0

def main():
	with open('B-large.in', 'r') as a:
	    text = a.readlines()
	    a.close()
	b = open('B-large.out', 'w+')
	cases = int(text[0])
	for i in range(1, cases + 1):
	    stack = text[i].split()[0]
	    output = "Case #{}: {}".format(i, count_flips(stack) +  check_last(stack))
	    if i != cases:
	    	output += "\n"
	    b.write(output)
	b.close()

if __name__ == "__main__":
    main()