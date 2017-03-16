import sys
import collections

def distribute(topics, pos):
    stats = collections.defaultdict(lambda:collections.defaultdict(int))
    for topic in topics:
        word = topic.split()[pos]
        other = topic.split()[pos - 1]
        stats[word][other] += 1
        #stats[word].append((topic, other))

    result = {}
    for word, tops in stats.iteritems():
        if sum(tops.itervalues()) > 1:
            if len(tops) == 1:
                tops[tops.keys()[0]] -= 1
            result[word] = tops
    return result

def solve(topics):
    d1 = distribute(topics, 0)
    d2 = distribute(topics, 1)

    result = 0
    for fw1, data1 in d1.iteritems():
        for fw2, count2 in data1.iteritems():
            try:
                data2 = d2[fw2]
            except KeyError:
                continue
            try:
                count1 = data2[fw1]
            except KeyError:
                continue
            result += min(count1, count2)

    return result

def main(inFile):
    with open(inFile) as inp, open(inFile.replace('.in', '.out'), 'w') as out:
        T = int(inp.readline().strip())
        for t in xrange(T):
            N = int(inp.readline().strip())
            topics = [inp.readline().strip() for _ in xrange(N)]
            out.write('Case #%d: %s\n' % (t + 1, solve(topics)))

if __name__ == '__main__':
    if len(sys.argv) < 2:
        sys.exit('Usage: %s input.in' % sys.argv[0])
    main(sys.argv[1])
