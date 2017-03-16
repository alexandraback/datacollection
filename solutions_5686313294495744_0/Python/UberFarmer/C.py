from sys import stdin
from copy import deepcopy, copy

DEBUG = False


def debug_print(*args):
    if DEBUG:
        print args


def main():
    num_cases = int(stdin.readline())
    for case in range(1, num_cases + 1):
        N = int(stdin.readline())
        unused_topics = []
        first_word_instances = {}
        second_word_instances = {}
        for t in range(N):
            topic = stdin.readline().split()
            unused_topics.append(topic)
            if topic[0] in first_word_instances:
                first_word_instances[topic[0]] += 1
            else:
                first_word_instances[topic[0]] = 1
            if topic[1] in second_word_instances:
                second_word_instances[topic[1]] += 1
            else:
                second_word_instances[topic[1]] = 1

        used_first_words = set()
        used_second_words = set()
        fakes = 0

        from copy import copy
        for topic in copy(unused_topics):
            if first_word_instances[topic[0]] == 1 or second_word_instances[topic[1]] == 1:
                # use the word as not a fake
                used_first_words.add(topic[0])
                used_second_words.add(topic[1])
                unused_topics.remove(topic)

        for topic in copy(unused_topics):
            if topic[0] in used_first_words and topic[1] in used_second_words:
                unused_topics.remove(topic)
                fakes += 1



        max_cover = recurse(unused_topics, used_first_words, used_second_words)
        fakes = fakes + max_cover + (len((unused_topics)) -
                      (len(first_word_instances) - len(used_first_words)) -
                      (len(second_word_instances) - len(used_second_words)))

        print "Case #{}: {}".format(case, fakes)

def recurse(unused_topics, used_first_words, used_second_words):
        possible_doubles = []
        for topic in unused_topics:
            if topic[0] not in used_first_words and topic[1] not in used_second_words:
                possible_doubles.append(topic)

        if not possible_doubles:
            return 0

        for double in possible_doubles:
            topics = copy(unused_topics)
            topics.remove(double)
            f = deepcopy(used_first_words)
            s = deepcopy(used_second_words)
            f.add(double[0])
            s.add(double[1])
            return 1 + recurse(topics, f, s)



if __name__ == "__main__":
    main()
