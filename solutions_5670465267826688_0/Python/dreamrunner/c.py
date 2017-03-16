test = int(input())

def cal(x, y):
    neg = False
    if len(x) == 2:
        neg = not neg
        x = x[1]
    if len(y) == 2:
        neg = not neg
        y = y[i]
    if x == "i":
        if y == "1":
            y = "i"
        elif y == "i":
            neg = not neg
            y = "1"
        elif y == "j":
            y = "k"
        else:
            neg = not neg
            y = "j"
    elif x == "j":
        if y == "1":
            y = "j"
        elif y == "i":
            neg = not neg
            y = "k"
        elif y == "j":
            neg = not neg
            y = "1"
        else:
            y = "i"
    elif x == "k":
        if y == "1":
            y = "k"
        elif y == "i":
            y = "j"
        elif y == "j":
            neg = not neg
            y = "i"
        else:
            neg = not neg
            y = "1"
    if neg:
        y = "-" + y
    return y


for t in range(1, test+1):
    print("Case #" + str(t) + ": ", end="")
    L, X = [int(i) for i in input().split(" ")]
    s = input()
    n = "1"
    step = 0
    for x in range(X):
        for c in s:
            n = cal(n, c)
            if step == 0 and n == "i":
                # print("Found i")
                n = "1"
                step += 1
            elif step == 1 and n == "j":
                # print("Found j")
                n = "1"
                step += 1
    if step == 2 and n == "k":
        print("YES")
    else:
        print("NO")

