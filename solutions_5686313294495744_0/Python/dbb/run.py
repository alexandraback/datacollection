import sys
import itertools

sys.stdin.readline()
casen = 0
while 1:
    ln = sys.stdin.readline()
    if not ln:
        break
    casen += 1
    nitems = int(ln.strip())

    first_words = {}
    second_words = {}
    topics = set()
    for _ in range(nitems):
        ln = sys.stdin.readline().strip()
        words = ln.split()
        if words[0] not in first_words:
            first_words[words[0]] = 0
        first_words[words[0]] += 1
        if words[1] not in second_words:
            second_words[words[1]] = 0
        second_words[words[1]] += 1
        topics.add((words[0], words[1]))

    # print first_words
    # print second_words
    # print topics
    topicset = set()
    firstset = set()
    secondset = set()

    # Any words where the first word or second words only 
    # appear once must be real
    for topic in topics:
        if first_words[topic[0]] == 1 or second_words[topic[1]] == 1:
            topicset.add(topic)
            firstset.add(topic[0])
            secondset.add(topic[1])

    remtopics = topics.difference(topicset)
    remfirst = set(first_words.keys()).difference(firstset)
    remsecond = set(second_words.keys()).difference(secondset)

    # print remtopics
    # print remfirst
    # print remsecond

    min_sets = max(len(remfirst), len(remsecond))
    max_sets = len(remfirst) + len(remsecond)

    last_set_size = 0
    found = False
    for i in range(min_sets, max_sets + 1):
        last_set_size = i
        subsets = itertools.combinations(remtopics, i)
        for subset in subsets:
            # print subset
            firstset = set()
            secondset = set()
            for topic in subset:
                firstset.add(topic[0])
                secondset.add(topic[1])
            if len(remfirst.difference(firstset)) == 0 and \
              len(remsecond.difference(secondset)) == 0:
                found = True
                break
        if found:
            break
    assert(found)
    assert(last_set_size >= min_sets)
    assert(last_set_size <= max_sets)
    print 'Case #%d: %d' % (casen, len(topics) - (len(topicset) + last_set_size))
