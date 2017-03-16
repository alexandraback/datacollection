test = int(input())

for t in range(1, test+1):
    print("Case #" + str(t) + ": ", end="")
    ins = input().split(" ")
    d = int(ins[0])
    c = [int(i) for i in ins[1]]
    total = c[0]
    add = 0
    for i in range(1, d+1):
        if total < i:
            add += i- total
            total = i
        total += c[i]
    print(add)

