#!/usr/bin/python3

vowels = {'a', 'e', 'i', 'o', 'u'}

cn = int(input())
for cs in range(cn):
    ans = 0
    name, n = input().split()
    n = int(n)

    A = [0]*len(name)
    z = 0
    for i in range(len(name)):
        if not name[i] in vowels:
            z += 1
        else:
            z = 0
        A[i] = z

    #print(A)

    prev = 0
    for i in range(len(A)):
        if A[i] >= n:
            a = (i - n + 1)
            b = len(A) - i
            ia = a - prev + 1
            prev = a + 1
            #print(ia, b)
            ans += ia * b

    print("Case #" + str(cs + 1) + ":", ans)
exit()
