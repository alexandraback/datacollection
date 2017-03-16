num = input()
for testcase in xrange(num):
	line = raw_input()
	(level, people) = line.split()
	level = int(level)
	people = [int(i) for i in people]
	addFunc = lambda x:x if (x > 0) else 0
	(ans,total) = reduce(lambda (ans, total), y:[ans + (y > total), max(y, total) + people[y]] , range(1,len(people)),  [0, people[0]]);
	print "Case #"+str(testcase + 1)+":" ,ans
