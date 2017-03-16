with open('C-small-attempt3.in', 'rb') as f:
    lines = map(lambda x: x.replace('\n',''), f.readlines())
    cases = int(lines[0])
    lines = lines[1:]

with open('outC.txt', 'wb') as out:
    for case in range(cases):
        print 'Case ' + str(case + 1) + ' / ' + str(cases)
        num_topics = int(lines[0])
        topics = []

        topics_a = []
        topics_b = []
        real_topics_a = []
        real_topics_b = []
        for i in range(num_topics):
            (a, b) = lines[i + 1].split()
            topics.append((a, b))
            topics_a.append(a)
            topics_b.append(b)

        delete_topic = []
        for topic in topics:
            if topics_a.count(topic[0]) == 1 or \
                            topics_b.count(topic[1]) == 1:
                real_topics_a.append(topic[0])
                real_topics_b.append(topic[1])
                delete_topic.append(topic)
        for topic in delete_topic:
            topics.remove(topic)

        best = None
        best_count = -1
        while True:
            for i in topics:
                if real_topics_a.count(i[0]) == 0:
                    equals_a = filter(lambda x: x[0] == i[0], topics)
                    if len(equals_a) > 1:
                        find_a = 0
                        best_a = None
                        for x in equals_a:
                            count = 0
                            for y in topics:
                                if y != x:
                                    if real_topics_a.count(y[0]) == 0 and \
                                         y[0] == x:
                                        count += 1
                            if count > best_count:
                                best_count = count
                                best = x
                if real_topics_b.count(i[1]) == 0:
                    equals_a = filter(lambda x: x[1] == i[1], topics)
                    if len(equals_a) > 1:
                        find_a = 0
                        best_a = None
                        for x in equals_a:
                            count = 0
                            for y in topics:
                                if y != x:
                                    if real_topics_a.count(y[1]) == 0 and \
                                                    y[1] == x:
                                        count += 1
                            if count > best_count:
                                best_count = count
                                best = x
            if best is not None:
                topics.remove(best)
                real_topics_a.append(best[0])
                real_topics_b.append(best[1])
                best = None
                best_count = -1
            else:
                break

        delete_topic = []
        for topic in topics:
            if real_topics_a.count(topic[0]) == 0 or \
                            real_topics_b.count(topic[1]) == 0:
                delete_topic.append(topic)
        for topic in delete_topic:
            topics.remove(topic)

        result = len(topics)

        out.write('Case #' + str(case + 1) + ': ' + str(result) + '\n')
        lines = lines[num_topics + 1:]








