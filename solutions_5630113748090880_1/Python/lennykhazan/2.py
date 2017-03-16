import operator

T = int(input())

def solve():
    N = int(input())
    occur = dict()
    for i in range(2*N-1):
        for x in input().split(' '):
            if int(x) in occur:
                occur[int(x)] += 1
            else:
                occur[int(x)] = 1

    missing = []

    for key, val in occur.items():
        if val % 2 == 1:
            missing.append(key)

    missing.sort()

    return ' '.join([str(x) for x in missing])


for t in range(T):
    print('Case #' + str(t+1) + ': ' + solve())
