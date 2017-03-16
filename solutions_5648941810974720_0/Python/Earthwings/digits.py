'''
Created on 30.04.2016

@author: Dennis Nienhüser <nienhueser@kde.org>
'''

import argparse

def remove(digit, character, word, number):
    if character in number:
        for char in word:
            number = number.replace(char, '', 1)
        return digit, number
    return None, number

def removeAll(numbers, digit, character, word, number):
    found = True
    while found is not None:
        found, number = remove(digit, character, word, number)
        if found is not None:
            numbers.append(found)
    return number

def digits(number):
    numbers = []
    number = removeAll(numbers, '0', 'Z', 'ZERO', number)
    number = removeAll(numbers, '2', 'W', 'TWO', number)
    number = removeAll(numbers, '6', 'X', 'SIX', number)
    number = removeAll(numbers, '8', 'G', 'EIGHT', number)
    number = removeAll(numbers, '3', 'T', 'THREE', number)
    number = removeAll(numbers, '7', 'S', 'SEVEN', number)
    number = removeAll(numbers, '5', 'V', 'FIVE', number)
    number = removeAll(numbers, '4', 'U', 'FOUR', number)
    number = removeAll(numbers, '9', 'I', 'NINE', number)
    number = removeAll(numbers, '1', 'O', 'ONE', number)
    numbers.sort()
    return ''.join(numbers)

def parse(filename):
    with open(filename) as file:
        numbers = file.readlines()
    return numbers[1:] if len(numbers) > 0 else []

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Code Jam 2016 Q1: Counting Sheep')
    parser.add_argument('file', help='Input text file')
    args = parser.parse_args()
    problem = parse(args.file)
    for index, number in enumerate(problem):
        print('Case #{}: {}'.format(index+1, digits(number)))
    