def check_insomnia(start):
	digits = [0 for _ in range(10)]

	x = int(start)
	while x > 0:
		digits[x % 10] = 1
		x = x // 10
	if sum(digits) == 10:
		return start
	
	for i in range(1,1000):
		x = int(start) * i
		while x > 0:
			digits[x % 10] = 1
			x = x // 10
		if sum(digits) == 10:
			return i * start
	return 'INSOMNIA'

def main():
	with open('A-large.in', 'r') as a:
	    text = a.readlines()
	    a.close()
	b = open('A-large.out', 'w+')
	cases = int(text[0])
	for i in range(1, cases + 1):
	    start = int(text[i].split()[0])
	    output = "Case #{}: {}".format(i, check_insomnia(start))
	    if i != cases:
	    	output += "\n"
	    b.write(output)
	b.close()

if __name__ == "__main__":
    main()