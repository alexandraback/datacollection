import time
import math

def run():
    f = open('C-small.in', 'r')
    lines = f.readlines()
    f.close()
    data = [line.rstrip() for line in lines]
    cases = int(lines[0])
    counter = 1

    g = open('Canswers.txt', 'w')

    for i in range(cases):
        line = data[counter].split(' ')
        g.write('Case #' + str(counter) + ': ' + str(solve(line)) + '\n')
        counter += 1
    g.close()

def listToString(things):
    string = ''
    for thing in things:
        string = string + str(thing) + ' '
    return string[:-1]

def solve(line):
    pass
