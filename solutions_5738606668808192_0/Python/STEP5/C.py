T = int(input())
N, J = list(map(int, input().split()))

anslist = []

def check(s):
    if(s[-1] == '0'):
        return None
    res = [s]
    for b in range(2, 11):
        num = int(s, b)
        div = -1
        for d in range(2, 1000):
            if num % d == 0:
                div = d
                break
        if div == -1:
            return None
        res.append(str(div))

    return res

cur = '1' + '0' * (N-1)
while len(anslist) < J:
    res = check(cur)
    if res != None:
        anslist.append(res)
    for i in range(N-1, -1, -1):
        if cur[i] == '1':
            cur = cur[:i] + '0' + cur[i+1:]
        else:
            cur = cur[:i] + '1' + cur[i+1:]
            break;

print('Case #1:')
for x in anslist:
    print(' '.join(x))
