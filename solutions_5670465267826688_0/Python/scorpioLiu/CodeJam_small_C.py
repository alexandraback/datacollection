import copy
fo = open('C-small-1.out', 'w')
data = open('C-small-attempt0.in').readlines()
data = data[1:]
num = int(len(data))

r = {
    '11': '1', '1i': 'i', '1j': 'j', '1k': 'k',
    'i1': 'i', 'ii': '-1', 'ij': 'k', 'ik': '-j',
    'j1': 'j', 'ji': '-k', 'jj': '-1', 'jk': 'i',
    'k1': 'k', 'ki': 'j', 'kj': '-i', 'kk': '-1',
}

result = ['YES', 'NO']

def get_char(x):
    if len(x) < 2:
        return x
    if x[0] == '-' and len(x) == 2:
        return x
    if len(x) == 2:
        return r[x]
    if len(x) == 3:
        y = r[x[1:]]
        if y[0] == '-':
            return y[1]
        else:
            return '-' + y

for z in range(num / 2):
    lx = [int(i) for i in data[2 * z].split()]
    x = lx[1]
    s = data[2 * z + 1].strip() * x
    flag = False
    idx = -1
    idx2 = -1
    last = s[0]
    for i in range(1, len(s) - 1):
        if last == 'i':
            idx = i
            break
        last = get_char(last + s[i]) 
    if idx > 0:
        last = s[idx]
        for j in range(1, len(s) - idx):
            if last == 'j':
                idx2 = j + idx
                break
            last = get_char(last + s[idx + j])
    if idx2 > 0:
        last = s[idx2]
        for c in s[idx2 + 1:]:
            last = get_char(last + c)
        if last == 'k':
            flag = True

    if flag:
        s = 'Case #%d: %s' % (z + 1, result[0])
    else:
        s = 'Case #%d: %s' % (z + 1, result[1])
    print s
    fo.write(s + '\n')