MG = 40;
def calc_pow2():
	pow2 = [1]
	for i in xrange(1, MG + 1):
		pow2.append(pow2[-1] * 2)
	print pow2
	return pow2
	
def elves_ancestors(p, q, pow2):	
	tmp = False;
	mini = 1
	for i in xrange(0, MG + 1):
		if (q == pow2[i]):
			tmp = True
			mini = i
	print tmp
	if not (tmp):
		return (False, 0);
	i = 1;
	#if ((pow2[40 - i] + pow2[i] - 1) * q <= pow2[40] * p):
	while (i <= 40):
		if (q <= pow2[i] * p):
			break
		i += 1
	
	g = i
	if (i > 40):
		return (False, g);
	return (True, g);


inputfile = open("in.txt", "r")
outputfile = open("out.txt", "w")
pow2 = calc_pow2()
t = int(inputfile.readline())
print t
for k in xrange(0, t):
	p, q = map(int, inputfile.readline().split("/"))
	print p, q
	res, g = elves_ancestors(p, q, pow2)
	if res:
		outputfile.write("Case #" + str(k + 1) + ": " + str(g) + "\n")
	else:
		outputfile.write("Case #" + str(k + 1) + ": impossible\n")
inputfile.close()
outputfile.close()

