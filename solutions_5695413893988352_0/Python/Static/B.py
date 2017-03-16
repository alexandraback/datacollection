# -*- coding: utf-8 -*-
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
import copy
from sys import argv

def load_file(filename):
    in_file = open(filename, encoding='utf-8')
    content = in_file.readlines()
    return content

def writeStringToFile(output, filename):
    out_file = open(filename + '.out', 'w')
    for i in output:
        out_file.write(i + '\n')
    out_file.close()

def allstrings(alphabet, length):
    """Find the list of all strings of 'alphabet' of length 'length'"""
    c = [[]]
    for i in range(length):
        c = [[x]+y for x in alphabet for y in c]
    return c

def solve(line):
    words = list(line.strip())
    possibilities = list(line.strip()).count('?')
    first, second = words[0], words[1]
    min_diff = 999999999

    temp = copy.copy(words)

    for i in allstrings([0,1,2,3,4,5,6,7,8,9], possibilities):
        for j in i:
            idx = 0
            for k in temp:
                if k != '?':
                    idx += 1
                else:
                    break
            temp[idx] = str(j)
        temp = (''.join(temp)).split()
        diff = abs(int(temp[0]) - int(temp[1]))
        if diff < min_diff:
            solucao = copy.copy(temp)
            min_diff = diff
        temp = copy.copy(words)

    print(solucao)

    return ' '.join(solucao)

if __name__ == "__main__":
    filename = argv[1]
    file = load_file(filename)
    n = int(file[0])
#    print(int(file[0]))
    out = []
    for i in range(1, n+1):
        line = file[i]
        out.append("Case #{0}: {1}".format(i, solve(line)))
#print(out)
writeStringToFile(out, filename)
