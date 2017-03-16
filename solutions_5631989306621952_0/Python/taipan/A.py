N = int(input())
n = 1

for i in range(N):
    s = input()

    b = s[0]
    f = ""

    print("Case #" + str(n) + ": ", end = "")
    for c in s:

        if c >= b:
            f = c + f
            b = c
        else:
            f = f + c

    print(f)
    n += 1
