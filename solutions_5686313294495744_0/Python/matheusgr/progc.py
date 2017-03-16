import sys

lines = sys.stdin.readlines()
cases = int(lines[0])
line = 1

for case in xrange(cases):
    n_topics = int(lines[line])
    firsts = {}
    seconds = {}
    fake = 0
    topics = []
    for _ in xrange(n_topics):
        line += 1
        first, second = lines[line].split()
        firsts[first] = firsts.get(first, 0) + 1
        seconds[second] = seconds.get(second, 0) + 1
        topics.append((first, second))
    topics.sort(key=lambda x: min(firsts[x[0]], seconds[x[1]]))
    firsts = set()
    seconds = set()
    for first, second in topics:
        if first in firsts and second in seconds:
            fake += 1
        firsts.add(first)
        seconds.add(second)
    line += 1
    print "Case #%i: %s" % (case + 1, fake)
