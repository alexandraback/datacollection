x = int(input())

for _ in range(x):
    S = input()
    current = S[0]
    count = 0
    for s in S:
        if s == '\n':
            break
        if s != current:
            count += 1
            current = s

    if current == '-':
        count += 1

    print("Case #"+str(_+1)+": "+str(count))