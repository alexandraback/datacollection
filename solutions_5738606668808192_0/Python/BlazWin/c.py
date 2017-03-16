t = int(input())
n, j = (int(x) for x in input().split())
print("Case #1:")
for i in range(2 ** (n - 1), 2 ** n):
    if i % 3 != 0 or i % 2 == 0:
        continue
    s = "{:b}".format(i)
    divs = []
    for h in range(2, 11):
        num = int(s, base = h)
        if num % 2 == 0:
            divs.append(2)
        elif num % 3 == 0:
            divs.append(3)
        elif num % 5 == 0:
            divs.append(5)
        elif num % 7 == 0:
            divs.append(7)
        else:
            break
    if len(divs) == 9:
        print(s, *divs)
        j -= 1
        if (j == 0):
            break