import sys
import re

input_file = open(sys.argv[1], 'r')
nb_tests = int(input_file.readline())

for i in range(nb_tests):
    #zero    z
    #one
    #two     w
    #three      h (eight)
    #four    u
    #five        f (four)
    #six     x
    #seven           z
    #eight   g
    #nine

    numbers = 10*[0]
    line = input_file.readline()
    #print(line)
    while line.find('Z') >= 0:
        numbers[0] += 1
        line = line.replace("Z", '', 1)
        line = line.replace("E", '', 1)
        line = line.replace("R", '', 1)
        line = line.replace("O", '', 1)
    while line.find('W') >= 0:
        numbers[2] += 1
        line = line.replace("T", '', 1)
        line = line.replace("W", '', 1)
        line = line.replace("O", '', 1)
    while line.find('U') >= 0:
        numbers[4] += 1
        line = line.replace("F", '', 1)
        line = line.replace("O", '', 1)
        line = line.replace("U", '', 1)
        line = line.replace("R", '', 1)
    while line.find('X') >= 0:
        numbers[6] += 1
        line = line.replace("S", '', 1)
        line = line.replace("I", '', 1)
        line = line.replace("X", '', 1)
    while line.find('G') >= 0:
        numbers[8] += 1
        line = line.replace("E", '', 1)
        line = line.replace("I", '', 1)
        line = line.replace("G", '', 1)
        line = line.replace("H", '', 1)
        line = line.replace("T", '', 1)
    while line.find('H') >= 0:
        numbers[3] += 1
        line = line.replace("T", '', 1)
        line = line.replace("R", '', 1)
        line = line.replace("H", '', 1)
        line = line.replace("E", '', 1)
        line = line.replace("E", '', 1)
    while line.find('F') >= 0:
        numbers[5] += 1
        line = line.replace("F", '', 1)
        line = line.replace("I", '', 1)
        line = line.replace("V", '', 1)
        line = line.replace("E", '', 1)
    while line.find('V') >= 0:
        numbers[7] += 1
        line = line.replace("S", '', 1)
        line = line.replace("E", '', 1)
        line = line.replace("V", '', 1)
        line = line.replace("E", '', 1)
        line = line.replace("N", '', 1)
    while line.find('I') >= 0:
        numbers[9] += 1
        line = line.replace("N", '', 1)
        line = line.replace("I", '', 1)
        line = line.replace("N", '', 1)
        line = line.replace("E", '', 1)
    while line.find('O') >= 0:
        numbers[1] += 1
        line = line.replace("O", '', 1)
        line = line.replace("N", '', 1)
        line = line.replace("E", '', 1)

    print('Case #', i+1, ": ", sep='', end='')
    for j in range(10):
        for k in range(numbers[j]):
            print(j, sep='', end='')
    print('')
