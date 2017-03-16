#!/usr/bin/python3

vowels = {'a', 'e', 'i', 'o', 'u'}

def count(name, a, b):
    res = 0
    for i in range(a, b):
        z = 0
        for j in range(i, b):
            if not name[j] in vowels:
                z += 1
            else:
                if z > res:
                    res = z
                z = 0
        if z > res:
            res = z
    return res

cn = int(input())
for cs in range(cn):
    ans = 0
    name, n = input().split()
    n = int(n)

    for i in range(len(name)):
        for j in range(i, len(name)):
            if count(name, i, j + 1) >= n:
                ans += 1

    print("Case #" + str(cs + 1) + ": " + str(ans))
exit()
