import copy
fo = open('D-small-1.out', 'w')
data = open('D-small-attempt5.in').readlines()
data = data[1:]
num = int(len(data))

result = ['GABRIEL', 'RICHARD']
res_map = {
    3: [[2, 3], [3, 3], [3, 4]],
    4: [[3, 4], [4, 4]],
}

for z in range(num):
    r = [int(i) for i in data[z].split()]
    b = sorted(r[1:])
    flag = False
    if r[0] == 1:
        flag = True
    elif r[0] == 2:
        if b[0] * b[1] % 2 == 0:
            flag = True
    else:
        if b in res_map[r[0]]:
            flag = True
    if flag:
        s = 'Case #%d: %s' % (z + 1, result[0])
    else:
        s = 'Case #%d: %s' % (z + 1, result[1])
    print s
    fo.write(s + '\n')
