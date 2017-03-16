import sys, random, time

def rankFile(soldiers):
    soldiers = map(int, soldiers.split(' '))
    # soldiers = [random.randint(0, 2500) for i in range(4950)]
    last = set([])
    for i in soldiers:
        num = soldiers.count(i)
        if num % 2 == 1:
            last.add(i)
    return ' '.join(map(str, sorted(list(last))))

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        numLines = int(test.readline().strip())
        soldiers = ''
        for j in range(2 * numLines - 1):
            soldiers += test.readline().strip() + " "
        print('Case #' + str(i + 1) + ': ' + str(rankFile(soldiers[:-1])))
        # start = time.time()
        # for i in range(50):
        #     rankFile(soldiers)
        #     print(i)
        # print(time.time() - start)
