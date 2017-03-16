#!/bin/python3
import sys


def in_string(string, sub_string):
    string = list(string)
    for char in sub_string:
        if char in string:
            string.remove(char)
        else:
            return (False, '')
    return (True, ''.join(string))
words = map(str.rstrip, sys.stdin.readlines()[1:])

number_words = ['EIGHT', 'ZERO', 'SIX', 'TWO', 'SEVEN', 'FIVE', 'FOUR', 'ONE', 'THREE', 'NINE']
number_nums = [8,0,6,2,7,5,4,1,3,9]
for index, word in enumerate(words):
    numbers = []
    for num, number in enumerate(number_words):
        result = in_string(word, number)
        while result[0]:
            numbers.append(number_nums[num])
            word = result[1]
            result = in_string(word, number)
    if word != '':
        print('ERROR'+word)
    print('Case #{:d}: {!s}'.format(index+1,''.join(map(str,sorted(numbers)))))
