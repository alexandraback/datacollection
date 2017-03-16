w = open("C:\Users\ANTON\PycharmProjects\CodeJam\CoinJam\Large-Output.txt", 'w')
N, J = 32, 500

basic = "1" + 30 * "0" + "1"
solutions = []
starting_pos = 2
while len(solutions) < 500:
    for i in xrange(starting_pos - 1, 31):
        for j in xrange(i + 1, 32, 2):
            a = basic[:i] + '1' + basic[i + 1:j] + '1' + basic[j + 1:]
            if a.count('1') % 2 != 0:
                print 'Alert ' + a
            else:
                solutions.append(basic[:i] + '1' + basic[i + 1:j] + '1' + basic[j + 1:])

    starting_pos += 2
    basic = "1" * (starting_pos - 1) + (32 - starting_pos) * "0" + "1"

print len(solutions[:500])
w.write("Case #1:\n")
for case in solutions[:500]:
    w.write(case + " 3 2 5 2 7 2 3 2 11\n")
