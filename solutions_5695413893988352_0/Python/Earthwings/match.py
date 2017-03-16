'''
Created on 30.04.2016

@author: Dennis Nienhüser <nienhueser@kde.org>
'''

import argparse
import copy

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K

def compareScore(a, b):
    assert(len(a) == 2)
    assert(len(b) == 2)
    a1 = int(a[0])
    a2 = int(a[1])
    b1 = int(b[0])
    b2 = int(b[1])
    diffA = abs(a1 - a2)
    diffB = abs(b1 - b2)
    if diffA == diffB:
        if a1 == b1:
            return -1 if a2 < b2 else 1
        return -1 if a1 < b1 else 1
    return -1 if diffA < diffB else 1 

def createNumbers(a, b, numbers):
    assert(len(a) == len(b))
    for i in range(len(a)):
        m = a[i]
        n = b[i]
        if len(numbers) == 0:
            for m in a[i]:
                for n in b[i]:
                    numbers.append([m, n])
        else:
            old = copy.copy(numbers)
            numbers.clear()
            for m in a[i]:
                for n in b[i]:
                    for num in old:
                        numbers.append([num[0] + m, num[1] + n])
    return numbers

def expand(a, b):
    rA = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'] if a == '?' else [a]
    rB = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9'] if b == '?' else [b]
    return rA, rB
    
    if a == '?' and b == '?':
        return ['0', '9'], ['0', '9']
    if a == '?' and b == '0':
        return ['0', '1', '9'], [b]
    if a == '0' and b == '?':
        return [a], ['0', '1', '9']
    if a == '?':
        return ['0','1', '9', b], [b]
    if b == '?':
        return [a], ['0', '1', '9', a]
    return [a], [b]
    

def score(c, j):
    assert(len(c) == len(j))
    one = []
    two = []
    for i in range(len(c)):
        a, b = expand(c[i], j[i])
        one.append(a)
        two.append(b)
    numbers = []
    numbers = createNumbers(one, two, numbers)
    
    return sorted(numbers, key=cmp_to_key(compareScore))[0]


def parse(filename):
    with open(filename) as file:
        numbers = file.readlines()
    return numbers[1:] if len(numbers) > 0 else []


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Code Jam 2016 R1B: Close Match')
    parser.add_argument('file', help='Input text file')
    args = parser.parse_args()
    problem = parse(args.file)
    for index, number in enumerate(problem):
        numbers = number.replace('\n', '').split(' ')
        assert(len(numbers) == 2)
        result = score(numbers[0], numbers[1])
        print('Case #{}: {}'.format(index+1, ' '.join(result)))
    