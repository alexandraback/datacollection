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

def solve(line):
    word = list(line.strip())
    numbers = [(list("SIX"), '6'), (list("SEVEN"), '7'), (list("FIVE"), '5'), (list("EIGHT"), '8'), (list("ZERO"), '0'), (list("TWO"), '2'), (list("FOUR"), '4'), (list("NINE"), '9'), (list("ONE"), '1'), (list("THREE"), '3')]
    solution = ""
    for i in numbers:
        j_in = True
        while j_in == True:
            for j in i[0]:
                if i[0].count(j) > word.count(j):
                    j_in = False
            if j_in == True:
                for j in i[0]:
                    word.remove(j)
                solution += i[1]
    if len(word) != 0:
        print("deu errado", word)
        exit()
    return ''.join(sorted(solution))

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
