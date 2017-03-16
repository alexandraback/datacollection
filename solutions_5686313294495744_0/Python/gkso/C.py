

T = raw_input()
T = int(T)

for t_ in range(T):
    N = raw_input()
    N = int(N)
    topics_0 = []
    topics_1 = []

    for i in range(N):
        topic = raw_input()
        topic = topic.split()
        topics_0.append(topic[0])
        topics_1.append(topic[1])

    fake_num = 0
    i = 0
    l = N
    while i < l:
        topic_0 = topics_0[i]
        topic_1 = topics_1[i]
        flag_0 = False
        flag_1 = False
        for ii in range(l):
            if ii == i: continue
            if topics_0[ii] == topic_0:
                flag_0 = True
            if topics_1[ii] == topic_1:
                flag_1 = True
        if flag_0 and flag_1:
            #print(topic_0, topic_1) 
            fake_num += 1
            topics_0.remove(topic_0)
            topics_1.remove(topic_1)
            i -= 1
            l -= 1
        i += 1

    max_fake_num = fake_num
    print("Case #%d: %d" % (t_ + 1, max_fake_num))

    


