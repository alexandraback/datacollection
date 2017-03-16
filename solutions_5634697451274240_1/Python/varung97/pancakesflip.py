import sys, random, time

# def pancakesflip(pancakes):
#     b = (1 << len(bin(pancakes)[2:])) - 1
#     i = 0
#
#     while pancakes != 0:
#         pancakes ^= b
#         b = (1 << len(bin(pancakes)[2:])) - 1
#         i += 1
#     return i

def new(pancakes):
    i = 0
    state = 0
    for pancake in pancakes:
        if state ^ pancake:
            i += 1
            state ^= 1
    return i

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        pancakes = map(lambda x: 0 if x == '+' else 1, list(test.readline().strip())[::-1])
        print('Case #' + str(i + 1) + ': ' + str(new(pancakes)))
    #     pancakes = int(''.join(map(lambda x: '0' if x == '+' else '1', list(pancakes))[::-1]), 2)
    #     print('Case #' + str(i + 1) + ': ' + str(pancakesflip(pancakes)))
