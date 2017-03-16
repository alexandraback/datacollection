T = eval(input())

def name(num, used):
    numstr = str(num)
    for char in numstr:
        used[ord(char) - ord('0')] = 1

for caseNum in range(T):
    N = eval(input())
    if N == 0:
        print('Case #{}: INSOMNIA'.format(caseNum + 1))
    else:
        used = [0 for _ in range(10)]
        last = N
        name(last, used)
        while min(used) == 0:
            last += N
            name(last, used)
        print('Case #{}: {}'.format(caseNum + 1, last))
