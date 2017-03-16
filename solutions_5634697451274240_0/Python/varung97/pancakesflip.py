import sys, random, time

def pankcakesflip(pancakes):
    pancakes = int(''.join(map(lambda x: '0' if x == '+' else '1', list(pancakes))[::-1]), 2)
    b = (1 << len(bin(pancakes)[2:])) - 1
    i = 0

    while pancakes != 0:
        pancakes ^= b
        b = (1 << len(bin(pancakes)[2:])) - 1
        i += 1
    return i

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        print('Case #' + str(i + 1) + ': ' + str(pankcakesflip(test.readline().strip())))
