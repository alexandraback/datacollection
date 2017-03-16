n = int(raw_input())

for testcase in range(n):
	[k,line] = raw_input().split()
	friends = 0
	fake_friends = 0
	for i in range(int(k)):
		friends += int(line[i])
		while friends+fake_friends < i+1:
			fake_friends += 1
	print "Case #%s: %s"%(testcase+1,fake_friends)

