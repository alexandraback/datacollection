from collections import Counter
with open('C-small-attempt1.in') as f:
    with open('c.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            N = int(f.readline())
            topics = []
            fake = 0
            remq = []
            for j in range(N):
                topic = f.readline().split()
                if topic not in topics:
                    topics.append(topic)
                else:
                    fake += 1
            while topics:
                # print topics
                words0, words1 = zip(*topics)
                w0 = Counter(words0)
                w1 = Counter(words1)
                uniq0 = map(lambda x: x[0], filter(lambda (x, y): y == 1, w0.items()))
                uniq1 = map(lambda x: x[0], filter(lambda (x, y): y == 1, w1.items()))
                if uniq1 and uniq0:
                    fake0 = []
                    fake1 = []
                    for k, topic in enumerate(topics):
                        if topic[0] in uniq0:
                            remq.append(k)
                            if topic[1] not in uniq1:
                                fake1.append(topic[1])
                        elif topic[1] in uniq1:
                            remq.append(k)
                            fake0.append(topic[0])
                    remq.reverse()
                    for k in remq:
                        topics.pop(k)
                    remq = []
                    for k, topic in enumerate(topics):
                        if topic[1] in fake1 and topic[0] in fake0:
                            fake += 1
                            remq.append(k)
                    remq.reverse()
                    for k in remq:
                        topics.pop(k)
                    remq = []
                else:
                    for topic in topics:
                        if w0[topic[0]] > 1 and w1[topic[1]] > 1:
                            w0[topic[0]] -= 1
                            w1[topic[1]] -= 1
                            fake += 1
                    break

            res = fake

            print 'Case #{i}: {z}'.format(z=res, i=i)
            out.write('Case #{i}: {z}\n'.format(z=res, i=i))