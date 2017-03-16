# Google Codejam 2015 Qualifier
# Standing Ovation

testcases = int(raw_input().strip())
for testcase in xrange(testcases):
	maxshy, data = raw_input().split()
	maxshy = int(maxshy)
	risen = 0
	required = 0
	for shyness in xrange(maxshy+1):
		count = int(data[shyness])
		#print "Shyness:", shyness, "Count:", count, "Risen", risen,
		if risen >= shyness:
			risen += count
		else:
			required += (shyness - risen)
			risen = shyness + count
		#print "Postrisen:", risen, "Required", required
	print "Case #%d:" % (testcase+1), required
