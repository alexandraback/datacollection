digit = {}


def init():
    for i in range(0, 10):
        digit[str(i)] = 0


def check(num):
    for value in num.values():
        if value == 0:
            return False
    return True


def counting_sheep(test_num, N):
    init()
    num_map = {}
    times = 1
    while True:
        x_ = times * int(N)
        # print x_
        times += 1
        if x_ in num_map:
            return 'Case ' + '#' + str(test_num) + ': ' + 'INSOMNIA'
        else:
            num_map[x_] = 0
        for i in str(x_):
            digit[i] += 1
        if check(digit):
            return 'Case ' + '#' + str(test_num) + ': ' + str(x_)


f = open('A-small-attempt2.in')
f1 = open('output.txt', 'wb')

i = 1

test_case = f.readline()

for line in f.readlines():
    # print x

    f1.write(counting_sheep(i, line) + '\n')
    i += 1
    # print counting_sheep(i, x)

f.close()
f1.close()
