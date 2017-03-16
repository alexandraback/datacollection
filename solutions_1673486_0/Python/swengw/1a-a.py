f = open('A-small-attempt1.in', 'r')
ans = open('out.txt', 'w')

for i in range(int(f.readline().strip())):
	data = [int(x) for x in f.readline().strip().split()]
	a = data[0]
	b = data[1]
	prob = [float(x) for x in f.readline().strip().split()]
	options = []

	# keep typing case
	prob_correct = 1
	for j in prob:
		prob_correct *= j
	options.append((b-a+1)*prob_correct+(2*b-a+2)*(1-prob_correct))
	# enter case
	options.append(2+b)
	# case where backspace a times
	options.append(a+b+1)
	# all the other cases
	# num keys = prob_optimal * k_right + ...
	for c in range(1, a):
		k_right = 2*c+b-a+1
		k_wrong = k_right + b+ 1
		prob_optimal = 1
		for j in range(0, a-c):
			prob_optimal *= prob[j]
		options.append(prob_optimal*k_right + (1-prob_optimal)*k_wrong)
		print prob_optimal*k_right + (1-prob_optimal)*k_wrong

	result = min(options)
	ans.write("Case #" + str(i+1) + ": " + str(result) + "\n")
	print "Case #" + str(i+1) + ": " + str(result)

f.close()
ans.close()
