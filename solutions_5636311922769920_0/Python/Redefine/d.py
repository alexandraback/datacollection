def reveal(tiles, complexity):
	total = tiles ** complexity
	num_deduced = 0
	revealed = []
	while num_deduced * complexity + complexity <= tiles:
		offset = num_deduced * complexity
		index = 0
		for i in range(0, complexity):
			index += (offset + i) * (tiles ** (complexity - i - 1))
		revealed.append(index + 1)
		num_deduced += 1
	if num_deduced * complexity < tiles:
		offset = num_deduced * complexity
		index = 0
		for i in range(0, complexity):
			if i >= tiles - offset:
				index += (tiles - 1) * (tiles ** (complexity - i - 1))
			else:
				index += (offset + i) * (tiles ** (complexity - i - 1))
		revealed.append(index + 1)
	return revealed


def main():
	with open('D-small-attempt1.in', 'r') as a:
	    text = a.readlines()
	    a.close()
	b = open('D-small-attempt1.out', 'w+')
	cases = int(text[0])
	for i in range(1, cases + 1):
		K = int(text[i].split()[0])
		C = int(text[i].split()[1])
		S = int(text[i].split()[2])
		revealed = reveal(K, C)
		if len(revealed) > S:
			b.write("Case #{}: IMPOSSIBLE\n".format(i))
		else:
			b.write("Case #{}: {}\n".format(i, ' '.join(map(str, revealed))))
	b.close()

if __name__ == "__main__":
    main()