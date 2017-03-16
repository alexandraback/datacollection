case = int(input().strip())
for i in range(case):
    n = int(input().strip())
    arr = []
    for j in range(2*n-1):
        arr.extend(list(map(int,input().strip().split())))
    answer = []
    index = 1
    while len(answer) < n:
        if arr.count(index) % 2 == 1:
            answer.append(str(index))
        index += 1
    print("Case #%i: %s" %(i+1, ' '.join(answer)))
