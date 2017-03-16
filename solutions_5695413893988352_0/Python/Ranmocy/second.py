import sys

global result
global minimal_diff
result = ['', '']
minimal_diff = sys.maxint

def search(i, n, b1, b2):
    global result
    global minimal_diff
    while i < n and b1[i] != '?' and b2[i] != '?':
        i += 1
    if i >= n:
        a = ''.join(b1)
        b = ''.join(b2)
        t = abs(int(a) - int(b))
        if t < minimal_diff:
            minimal_diff = t
            result = [a, b]
        elif t == minimal_diff:
            if int(result[0]) > int(a):
                result = [a, b]
            elif int(result[0]) == int(a) and int(result[1]) > int(b):
                result = [a, b]
        return
    if b1[i] == '?':
        possible_b1 = set(['0', '1', '9'])
        if b2[i] != '?':
            t = int(b2[i])
            possible_b1.add(str(t))
            if t > 0:
                possible_b1.add(str(t-1))
            if t < 9:
                possible_b1.add(str(t+1))
    else:
        possible_b1 = set(b1[i])
    if b2[i] == '?':
        possible_b2 = set(['0', '1', '9'])
        if b1[i] != '?':
            t = int(b1[i])
            possible_b2.add(str(t))
            if t > 0:
                possible_b2.add(str(t-1))
            if t < 9:
                possible_b2.add(str(t+1))
    else:
        possible_b2 = b2[i]
    for a in possible_b1:
        t = b1[i]
        b1[i] = a
        for b in possible_b2:
            tt = b2[i]
            b2[i] = b
            search(i+1, n, b1, b2)
            b2[i] = tt
        b1[i] = t

def solve(boards):
    assert len(boards) == 2
    b1 = boards[0]
    b2 = boards[1]
    print b1, b2
    assert len(b1) == len(b2)

    n = len(b1)
    i = 0
    b1_is_greater = None
    while i < n:
        if b1[i] == '?' and b2[i] == '?':
            if i+1 < n and (b1[i+1] == '?' and b2[i+1] == '?'):
                b1[i] = '0'
                b2[i] = '0'
            else:
                break;
        else:
            break;

    global result
    global minimal_diff
    result = ['', '']
    minimal_diff = sys.maxint
    search(0, n, b1, b2)

    return ' '.join(result)

# def solve(boards):
#     assert len(boards) == 2
#     b1 = boards[0]
#     b2 = boards[1]
#     print b1, b2
#     assert len(b1) == len(b2)

#     n = len(b1)
#     i = 0
#     b1_is_greater = None
#     while i < n:
#         if b1[i] == '?' and b2[i] == '?':
#             b1[i] = '0'
#             b2[i] = '0'
#         elif b1[i] == '?':
#             b1[i] = b2[i]
#         elif b2[i] == '?':
#             b2[i] = b1[i]
#         elif b1[i] != b2[i]:
#             b1_is_greater = b1[i] >= b2[i]
#             break
#         i += 1
#     while i < n:
#         if b1[i] == '?':
#             if b1_is_greater:
#                 b1[i] = '0'
#             else:
#                 b1[i] = '9'
#         if b2[i] == '?':
#             if b1_is_greater:
#                 b2[i] = '9'
#             else:
#                 b2[i] = '0'
#         i += 1

#     return ''.join(b1) + ' ' + ''.join(b2)

with open('second.in', 'r') as fin:
    with open('second.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            boards = map(list, fin.readline().rstrip().split(' '))
            fout.write('Case #{0}: {1}\n'.format(i, solve(boards)))
