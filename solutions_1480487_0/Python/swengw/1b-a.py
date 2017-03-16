f = open('A-small-attempt0.in', 'r')
ans = open('out.txt', 'w')

for i in range(int(f.readline().strip())):
	data = [int(x) for x in f.readline().strip().split()]
	num = data[0]
	scores = data[1:]
	X = float(sum(scores))
	goal = 2*X/len(scores)
	answer = [str((goal-x)/X)for x in scores]
	result = ""
	for answ in answer:
		result += answ + ' '
	ans.write("Case #" + str(i+1) + ": " + str(result) + "\n")
	print "Case #" + str(i+1) + ": " + str(result)

f.close()
ans.close()
