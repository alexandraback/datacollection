num_test_cases = input()
for nc in xrange(1, num_test_cases+1):
	first_topics = {}
	second_topics = {}
	first_topics_available = set()
	second_topics_available = set()
	N = input()
	topics = []
	for i in xrange(N):
		topics.append(raw_input())
		ft, st = topics[-1].split()
		first_topics.setdefault(ft, 0)
		first_topics[ft] += 1
		second_topics.setdefault(st, 0)
		second_topics[st] += 1
	trueman = 0
	for topic in topics:
		first_topic, second_topic = topic.split()
		if first_topics[first_topic] == 1 or second_topics[second_topic] == 1:
			trueman += 1
	print "Case #%d: %s" % (nc, len(topics) - trueman)