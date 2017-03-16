# o = open("C:\Users\ANTON\PycharmProjects\CodeJam\CoinJam\Tests.txt")
w = open("C:\Users\ANTON\PycharmProjects\CodeJam\CoinJam\Small-Output.txt", 'w')


def find_factor(number):
    for x in xrange(2, int(number ** .5) + 1):
        if number % x == 0:
            return x

    return -1


def find_bases(number):
    lst = []
    for base in xrange(2, 11):
        num = 0
        for index, j in enumerate(reversed(str(number))):
            num += int(j) * (base ** index)

        if find_factor(num) != -1:
            lst.append(str(find_factor(num)))
        else:
            return -1
    return lst

# input_lines = [i.strip('\n').split(' ') for i in o]
# cases = int(input_lines.pop(0)[0])

N, J = 16, 50
jam_coins = dict()
start = 32769
while len(jam_coins) < J:
    z = find_bases(bin(start)[2:])
    if z != -1:
        jam_coins[bin(start)[2:]] = z

    start += 2

w.write("Case #1:\n")
for keys in jam_coins.keys():
    w.write(str(keys) + ' ' + ' '.join(jam_coins[keys]) + '\n')
