from collections import Counter

file = 'C-small-attempt0.in'

def technobabble(topics):
    real_firsts = set()
    real_seconds = set()

    fakes = 0

    while topics:
        firsts, seconds = zip(*topics)
        firsts_counter = Counter(firsts)
        seconds_counter = Counter(seconds)
        ranked_topics = [((firsts_counter[first] + seconds_counter[second]), first, second) for first, second in topics]
        highest_first, highest_second = list(sorted(ranked_topics))[0][1:]
        real_firsts.add(highest_first)
        real_seconds.add(highest_second)
        possible_fakes = len(topics) - 1
        topics = [(first, second) for first, second in topics if not first in real_firsts or not second in real_seconds]
        fakes += possible_fakes - len(topics)

    return fakes



with open(file) as handle:
  T = int(handle.readline())

  for t in range(T):
    N = int(handle.readline())
    topics = []
    for n in range(N):
        topics.append(handle.readline().strip().split())

    print "Case #{}: {}".format(t + 1, technobabble(topics))
