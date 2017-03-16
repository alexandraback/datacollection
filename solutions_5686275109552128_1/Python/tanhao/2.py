num = input()
for testCase in xrange(num):
	plates = input()
	a = map(int, raw_input().split())
	
	print "Case #"+str(testCase + 1) + ":", min([sum(map(lambda x:(x-1)/i, a)) + i for i in range(1,max(a) + 1)])
