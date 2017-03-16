# -*- coding: utf-8 -*-
import fileinput
import collections
import itertools

numbers_map = {
    "ZERO": 0,
    "ONE": 1,
    "TWO": 2,
    "THREE": 3,
    "FOUR": 4,
    "FIVE": 5,
    "SIX": 6,
    "SEVEN": 7,
    "EIGHT": 8,
    "NINE": 9
}

order = ["SIX", "ZERO", "TWO", "EIGHT", "THREE", "FOUR", "FIVE", "SEVEN", "NINE", "ONE"]


def make_hist(string):
    hist = collections.defaultdict(int)
    for c in string:
        hist[c] += 1
    return hist


def contains_hist(hist, other):
    for character, count in other.iteritems():
        if hist[character] < count:
            return False
    return True


def remove_hist(hist, other):
    for character, count in other.iteritems():
        hist[character] -= count

def get_all_number_word(input_string, histograms):
    input_hist = make_hist(input_string)
    found_words = []
    for word in order:
        while contains_hist(input_hist, histograms[word]):
            remove_hist(input_hist, histograms[word])
            found_words.append(word)
    return found_words


def convert_to_number(words):
    c = [numbers_map[x] for x in words]
    c.sort()
    return "".join(itertools.imap(str, c))

def run():
    words_hist = {word: make_hist(word) for word in order}
    in_stream = fileinput.input()
    cases_count = int(in_stream.readline())

    for case in xrange(cases_count):
        line = in_stream.readline().strip()
        number = convert_to_number(get_all_number_word(line, words_hist))
        print("Case #{0}: {1}".format(case + 1, number))


if __name__ == "__main__":
    run()
