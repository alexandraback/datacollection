n = int(raw_input())

def count_fake(topics):
	word_bag_1 = set()
	word_bag_2 = set()

	for topic in topics:
		[w1, w2] = topic.split(" ")
		word_bag_1.add(w1)
		word_bag_2.add(w2)

	word_bag_1_final = word_bag_1 - word_bag_2
	word_bag_2_final = word_bag_2 - word_bag_1
	# print word_bag_1, word_bag_2
	# print word_bag_1_final, word_bag_2_final

	fake_topics_bag = set()
	for i in set(word_bag_1_final):
		for j in set(word_bag_2_final):
			fake_topic = i + " " + j
			fake_topics_bag.add(fake_topic)

	topics_bag  = set(topics)
	# print topics_bag
	# print fake_topics_bag
	# print fake_topics_bag - topics_bag

	return len(fake_topics_bag - topics_bag)


for i in range(n):
	m = int(raw_input())
	topics = []
	for j in range(m):
		topics.append(raw_input())

	print "Case #" + str(i+1) + ": " + str(count_fake(topics))