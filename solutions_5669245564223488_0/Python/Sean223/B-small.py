__author__ = 'Sean'

from itertools import permutations
from math import factorial

def check_string(string):
    for i in range(len(string)):
        j = i
        while j < len(string) and string[j] == string[i]:
            j += 1
        while j < len(string):
            if string[j] == string[i]:
                return False
            j += 1
    return True

def solve(cars):
    rv = 1
    ends = []
    middle = set()

    for car in cars:
        if not check_string(car):
            print("Malformed car")
            return 0

        for char in car:
            if char in middle:
                print("Middle char problem.")
                return 0

        start = car[0]
        end = car[len(car) - 1]

        ends.append([start, end])

        for i in range(len(car)):
            if i == 0 or i >= len(car) - 1:
                pass
            else:
                if car[i] == car[0] or car[i] == car[len(car) - 1]:
                    pass
                else:
                    middle.add(car[i])

    countsLeft = []
    countsRight = []

    for i in range(len(ends)):
        pair = ends[i]
        if pair[0] == pair[1]:
            continue

        foundOneLeft = False
        foundOneRight = False

        for j in range(len(ends)):
            if i == j:
                continue
            other = ends[j]
            if not other[0] == other[1]:
                if other[0] == pair[0]:
                    print("Two startings duplicate")
                    return 0
                if other[1] == pair[1]:
                    print("Two endings duplicate")
                    return 0

                if other[0] == pair[1]:
                    if foundOneLeft:
                        print("found two")
                        return 0
                    else:
                        foundOneLeft = True

                if other[1] == pair[0]:
                    if foundOneRight:
                        print("found two")
                        return 0
                    else:
                        foundOneRight = True


        countsLeft.append(1 if foundOneLeft else 0)
        countsRight.append(1 if foundOneRight else 0)

    if countsLeft.count(0) == 0 or countsRight.count(0) == 0:
        print("counts was zero.")
        return 0

    singleCars = []

    done = False

    while not done:
        done = True
        for i in range(len(cars)):
            car = cars[i]
            if len(car) == 1 or car[0] == car[len(car) - 1]:
                cars.pop(i)
                singleCars.append(car[0])
                done = False
                break

    freeCars = []

    while len(ends) > 0:
        car = ends.pop()
        free = True
        for i in range(len(ends)):
            second = ends[i]
            if second[0] == car[1]:
                second[0] = car[0]
                free = False
                break
            elif second[1] == car[0]:
                second[1] = car[1]
                free = False
                break

        if free:
            freeCars.append(car)

    while len(singleCars) > 0:
        letter = singleCars.pop()
        letterCount = 1 + singleCars.count(letter)

        while letter in singleCars:
            singleCars.remove(letter)

        merged = False

        for car in freeCars:
            if car[0] == letter or car[1] == letter:
                print("adding {0} factorial for free letter {1}".format(letterCount, letter))
                rv *= factorial(letterCount)
                rv %= 1000000007
                merged = True
                break

        if not merged:
            freeCars.append([letter, letter])

    print(freeCars)

    rv *= factorial(len(freeCars))
    rv %= 1000000007

    return rv

fileIn = open('B-small.in', 'r')
fileLines = fileIn.readlines()
fileIn.close()

it = iter(fileLines)

numbCases = int(next(it))

output = ""

for case in range(numbCases):
    N = int(next(it))
    cars = next(it).strip().split()

    output += "Case #{0}: {1}\n".format(case + 1, solve(cars))


with open('small.txt', 'w') as fileOut:
    fileOut.write(output)
