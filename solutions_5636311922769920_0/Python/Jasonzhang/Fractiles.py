f = open('D-small-attempt0.in')
f1 = open('out.txt', 'wb')

test_case = f.readline().strip()

num = 1
for line in f.readlines():
    components = line.strip().split(' ')
    K = components[0]
    C = components[1]
    S = components[2]
    f1.write('Case #' + str(num) + ': ')
    f1.write('1')
    for s in range(2, int(S)+1):
        f1.write(' ' + str(s))
    f1.write('\n')
    num += 1

f.close()
f1.close()