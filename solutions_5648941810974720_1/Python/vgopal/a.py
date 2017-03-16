from collections import Counter

NUMBERS = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")

def remove(number_string, num_occurences, input_set):
    for l in number_string:
        input_set[l] -= num_occurences
        assert input_set[l] >= 0

def answer(S):
    numbers = list(NUMBERS)
    input_set = Counter()
    for l in S:
        input_set[l] += 1
    answer = []
    while numbers:
        counter = Counter()
        for number in numbers:
            for letter in str(number):
                counter[letter] += 1
        for number in numbers:
            for letter in str(number):
                if counter[letter] == 1:
                    answer.extend([NUMBERS.index(number)] * input_set[letter])
                    remove(number, input_set[letter], input_set)
                    numbers.remove(number)
                    break

    return ''.join([str(x) for x in sorted(answer)])


def old_answer(S):
    S = sorted(S)
    i = 0
    while True:
        phone_number = str(i)
        words = [NUMBERS[int(x)] for x in phone_number]
        letters = sorted([l for w in words for l in w])
        if letters == S:
            return ''.join(sorted(phone_number))
        i += 1

input_file = open('a-large.txt')
num_cases = int(input_file.readline())
case_num = 1
while case_num <= num_cases:
    S = input_file.readline().strip()
    print "Case #{}: {}".format(case_num, answer(S))
    case_num += 1
