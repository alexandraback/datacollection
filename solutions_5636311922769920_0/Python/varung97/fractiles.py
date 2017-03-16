import sys

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        k = int(test.readline().strip().split()[0])
        print('Case #' + str(i + 1) + ': ' + str(range(1, k + 1))[1: -1].replace(',', ''))
