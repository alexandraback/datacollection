T = int(input())
for t in range(T):
    s = input()
    left = []
    right = []
    for l in s:
        if not left or l >= left[-1]:
            left.append(l)
        else:
            right.append(l)
    print('Case #%d:' % (t + 1), ''.join(left[::-1]) + ''.join(right))
