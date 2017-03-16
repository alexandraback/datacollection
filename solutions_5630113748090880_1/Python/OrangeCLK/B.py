T = eval(input())

for caseNum in range(T):
    N = eval(input())
    lines = []
    for i in range(N * 2 - 1):
        lines.append([eval(x) for x in input().split()])
    count = [0 for _ in range(2501)]
    for line in lines:
        for num in line:
            count[num] += 1
    ans = []
    for i, num in enumerate(count):
        if num % 2 == 1:
            ans.append(i)
    print('Case #{}: {}'.format(caseNum + 1, ' '.join([str(x) for x in ans])))
