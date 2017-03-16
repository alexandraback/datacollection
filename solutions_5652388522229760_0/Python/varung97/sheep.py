import sys, random, time

def sheep(num):
    if num == 0:
        return "INSOMNIA"
    finalset = set(range(10))
    setnums = set(map(int, list(str(num))))
    i = 0
    while finalset != setnums:
        i += 1
        setnums |= set(map(int, list(str(num * i))))
    return num * i

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        print('Case #' + str(i + 1) + ': ' + str(sheep(int(test.readline().strip()))))
    # start = time.time()
    # for i in range(1000001):
    #     sheep(i)
    #     if i % 100000 == 0:
    #         print(sheep(i))
    # print time.time() - start
