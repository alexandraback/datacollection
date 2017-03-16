f = open('D-small-attempt0.in')
f1 = open('out.txt', 'wb')

test_case = f.readline().strip()

num = 1
for line in f.readlines():
    components = line.strip().split(' ')
    K = int(components[0])
    C = int(components[1])
    S = int(components[2])
    f1.write('Case #' + str(num) + ': ')
    if C == 1:
        if S >= K:
            f1.write('1')
            for s in range(2, S + 1):
                f1.write(' ' + str(s))
        else:
            f1.write('IMPOSSIBLE')
    else:
        if S < K - 1:
            f1.write('IMPOSSIBLE')
        elif K == 1:
            f1.write('1')
        else:
            f1.write('2')
            for i in range(3, K + 1):
                f1.write(' ' + str(i))
    f1.write('\n')
    num += 1

f.close()
f1.close()
