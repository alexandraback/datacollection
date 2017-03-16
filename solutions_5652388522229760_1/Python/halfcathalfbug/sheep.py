import sys

def extract(num):
    while not num == 0:
        yield num % 10
        num /= 10

case = 0
for line in sys.stdin:
    if case == 0:
        case += 1
        continue
    
    digits = [0] * 10
    num = int(line)
    original = num
    output = "Case #%d: " % case
    insomnia = True
    seen = set()

    while not num in seen:
        for d in extract(num):
            digits[d] += 1

        if all((i > 0 for i in digits)):
            output += str(num)
            insomnia = False
            break

        seen.add(num)
        num += original

    if insomnia:
        output += "INSOMNIA"

    print output
    case += 1
