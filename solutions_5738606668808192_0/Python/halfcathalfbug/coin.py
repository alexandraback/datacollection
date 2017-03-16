import sys

def pad(string, pad, count):
    if len(string) < count:
        return (pad * (count - len(string))) + string 
    return string

def binary_iter(count):
    i = 0
    while i < 2 ** count:
        yield pad("{0:b}".format(i), "0", count)
        i += 1

def first_div(num):
    if num <= 2:
        return num
    for i in xrange(2, 20):
        if num % i == 0:
            return i
    return num

def is_valid(coin):
    divs = [0] * 9
    index = 0
    for base in xrange(2, 10 + 1):
        num = int(coin, base)
        div = first_div(num)

        # Num is (pretty much) prime
        if num == div:
            return None
        divs[index] = div
        index += 1
    return divs


case = 0
for line in sys.stdin:
    if case == 0:
        case += 1
        continue

    length, count = map(int, line.split(' '))
    
    output = "Case #%d: " % case
    print output

    for i in binary_iter(length - 2):
        coin = "1" + i + "1"
        result = is_valid(coin)
        if result:
            print coin + ' ' + ' '.join(map(str, result))
            count -= 1

        if count == 0:
            break

    case += 1
