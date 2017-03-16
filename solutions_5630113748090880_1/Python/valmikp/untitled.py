


filename = "B-large_1.in"
f = open(filename, "r")
content = [x.strip('\n') for x in f.readlines()]
f.close()

f = open("output_B_1.out","w+")

n_case = int(content[0])
i = 1
idx = 1

while i <= n_case:

	count = [0]*2501

	n = int(content[idx])
	x = idx + 1
	while x < idx + (2*n):

		vari = content[x].split()
		for y in vari:
			count[int(y)] += 1
		x += 1

	idx = x

	out_string = ''
	for k,z in enumerate(count):
		if z%2 != 0:
			out_string = out_string + ' ' + str(k)

	f.write("Case #" + str(i) + ":" + out_string +"\n")


	i += 1


f.close()