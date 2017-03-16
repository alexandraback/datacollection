import math

possible_values = []


for i in range(40):
	possible_values.append(float(1)/pow(2, i))



q_file = "A-large.in"
out_file_name = "out_" + q_file

out_file = file(out_file_name, "w")

lines = file(q_file).readlines()

cases = int(lines[0])



for i in xrange(cases):
	p, q = lines[i + 1].split('/')

	if (float(q) / float(p) == (int(q)/int(p))):
		#print int(math.log(int(q)/int(p), 2))
		#continue
		pass

	sum = float(p) / float(q);

	first = None

	for j in range(40):
		while True:
			if (sum > 0 and possible_values[j] <= sum):
				sum -= possible_values[j]
				if (first == None):
					first = possible_values[j]
			else:
				break

	if (sum == 0):
		#print first
		ans = 0
		while first < 1:
			ans += 1
			first *= 2
			pass
		out_file.write("Case #" + str(i+1) + ": "  + str(ans) + "\n") 
	else:
		out_file.write("Case #" + str(i+1) + ": "  + "impossible" + "\n")


	

	



