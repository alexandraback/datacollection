DEBUG=1

def main():
    T = input()
    for i in range(T):
        N = input()
        topics = [raw_input().split() for j in range(N)]
        print 'Case #%d: %s' % (i+1, solve(topics))

# def solve(written_topics):
#     from collections import Counter
#     words1 = Counter()
#     words2 = Counter()
#     topics = []
#     for word1, word2 in written_topics:
#         words1[word1] += 1
#         words2[word2] += 1
#         topics.append((word1, word2))
#     count = 0
#     for word1, word2 in written_topics:
#         if words1[word1] > 1 and words2[word2] > 1:
#             count += 1
#     return count

def solve(written_topics):
    words1 = dict()
    words2 = dict()
    # topics = []
    for topic in written_topics:
        word1, word2 = topic
        words1[word1] = words1.get(word1, []) + [topic]
        words2[word2] = words2.get(word1, []) + [topic]
        # topics.append(topic)

    # if len(words1) == 1 or len(words2) == 1:
    #     return 0

    # keys1 = words1.keys()
    # keys2 = words2.keys()

    # for i0 in range(len(keys1)-1):
    #     for i1 in range()

    return len(written_topics) - max(len(words1), len(words2))
        

























if __name__ == '__main__':
    main()
