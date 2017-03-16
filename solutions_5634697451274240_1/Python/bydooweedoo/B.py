import sys

chars = dict({'-': '+', '+': '-'})

def getLines():
    return [line.rstrip('\n') for line in sys.stdin]

def flip(stack):
    result, length = '', len(stack)
    for index in range(0, length):
        result += chars[stack[length - index - 1]]
    return result

assert(flip('+---') == '+++-')
assert(flip('+-') == '+-')

def cutflip(stack, num=-1):
    num = len(stack) if num == -1 else num
    result, length = '', min(num, len(stack))
    return [flip(stack[0:length]), stack[length:]]

assert(cutflip('+---') == ['+++-', ''])
assert(cutflip('+---', 3) == ['++-', '-'])
assert(cutflip('----', 3) == ['+++', '-'])
assert(cutflip('----', 1) == ['+', '---'])
assert(cutflip('----', 4) == ['++++', ''])
assert(cutflip('----', 5) == ['++++', ''])
assert(cutflip('----', 1) == ['+', '---'])

def happy(char, index=0):
    return char[index] == '+'

assert(happy('+') == True)
assert(happy('-') == False)
assert(happy('++') == True)

def unhappyIndexOf(stack):
    for index in range(0, len(stack)):
        if not happy(stack, index):
            return index
    return -1

assert(unhappyIndexOf('+++') == -1)
assert(unhappyIndexOf('++-') == 2)
assert(unhappyIndexOf('-++') == 0)

def happyIndexOf(stack):
    for index in range(0, len(stack)):
        if happy(stack, index):
            return index
    return -1

assert(happyIndexOf('+++') == 0)
assert(happyIndexOf('++-') == 0)
assert(happyIndexOf('-++') == 1)
assert(happyIndexOf('---') == -1)

def unhappyLastIndexOf(stack):
    for index in range(len(stack) - 1, -1, -1):
        if not happy(stack, index):
            return index
    return -1

assert(unhappyLastIndexOf('+++') == -1)
assert(unhappyLastIndexOf('++-') == 2)
assert(unhappyLastIndexOf('-++') == 0)
assert(unhappyLastIndexOf('-+-+-') == 4)

def cutHappyTail(stack):
    if stack[-1] == '+':
        return stack[0:unhappyLastIndexOf(stack) + 1]
    return stack

assert(cutHappyTail('----+++') == '----')
assert(cutHappyTail('----++-') == '----++-')
assert(cutHappyTail('+++++') == '')

def solve(stack):
    if unhappyIndexOf(stack) == -1:
        return 0
    elif happyIndexOf(stack) == -1:
        return 1
    total = 0
    while len(stack) > 0:
        stack = cutHappyTail(stack)
        if len(stack) > 0:
            if stack[0] == '-':
                stack = flip(stack)
            else:
                stack = cutflip(stack, unhappyIndexOf(stack))
                stack = stack[0] + stack[1]
            total += 1
    return total

assert(solve('------') == 1)
assert(solve('++++++') == 0)
assert(solve('--+-') == 3)

lines = getLines()
nbCases = int(lines.pop(0))

for case in range(0, nbCases):
    stack = lines.pop(0)
    answer = solve(stack)
    print("Case #", (case + 1), ": ", answer, sep="")
