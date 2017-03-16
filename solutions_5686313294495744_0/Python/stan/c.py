import sys

def bitcount(n):
    return bin(n).count("1")

def ok(mask, topics):
    n = len(topics)
    non_fake_topic_first = set()
    non_fake_topic_second = set()
    fake_topics = []
    for i in xrange(n):
        if ((1 << i) & mask) != 0:
            non_fake_topic_first.add(topics[i][0])
            non_fake_topic_second.add(topics[i][1])
        else:
            fake_topics.append(topics[i])
    for ft in fake_topics:
        if ft[0] not in non_fake_topic_first or ft[1] not in non_fake_topic_second:
            return False
    return True

nt = int(sys.stdin.readline())
for t in xrange(1, nt + 1):
    n = int(sys.stdin.readline())
    topics = []
    for _ in xrange(n):
        topics.append(sys.stdin.readline().strip().split())
    ans = 0
    for mask in xrange(1 << n):
        if ok(mask, topics):
            ans = max(ans, n - bitcount(mask))
    print "Case #%d:" % t, ans
