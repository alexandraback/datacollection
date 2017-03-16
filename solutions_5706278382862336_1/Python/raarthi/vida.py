def main():
	t = input()
	i = 0
	while i < t:
		i += 1
		p,q = raw_input().split('/')
		p = float(p)
		q = float(q)
		probability = p/q;
		possible = False

		current_gen = 0
		min_gen = 0
		while current_gen < 40:
			current_gen += 1
			probability *= 2
			if(probability >= 1 and min_gen == 0):
				min_gen = current_gen
			prob_int = int(probability)
			if(probability - prob_int == 0) and min_gen != 0:
				possible = True
				break
		output_str = "Case #" + str(i) + ": "
		if possible:
			output_str +=  str(min_gen)
		else:
			output_str += "impossible"
		print output_str

main()
