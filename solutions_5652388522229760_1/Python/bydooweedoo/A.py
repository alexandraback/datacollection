import sys

def getLines():
    return [line.rstrip('\n') for line in sys.stdin]

def solve(number):
    if number == 0:
        return "INSOMNIA"
    current, index = number, 2
    numbers = set(str(current))
    while len(numbers) < 10:
        current = index * number
        numbers = numbers.union(set(str(current)))
        index += 1
    return current

lines = getLines()
nbCases = int(lines.pop(0))

for case in range(0, nbCases):
    number = int(lines.pop(0))
    answer = solve(number)
    print("Case #", (case + 1), ": ", answer, sep="")
