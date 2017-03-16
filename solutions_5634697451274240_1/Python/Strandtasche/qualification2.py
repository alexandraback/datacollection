import sys

file = sys.stdin
def getStr():
    return (file.readline())

cases = int(getStr())

# def flip(stack, depth):
#     front = stack[:depth]
#     back = stack[depth:]
#     front = front[::-1]
#     return front + back

for i in range(cases):
    pancakes = getStr()
    #pancakes = list(pancakesStr)
    counter = 0
    if len(pancakes) < 2:
        if pancakes == "+":
            print("Case #" + str(i + 1) + ": 0")
        else:
            print("Case #" + str(i + 1) + ": 1")
    else:
        things = pancakes.count("+-")
        things *= 2
        if pancakes[0] == '-':
            things += 1
        print("Case #" + str(i + 1) + ": " + str(things))


