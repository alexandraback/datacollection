t = int(input())

for i in range(1, t+1):
    n = int(input())
    ints = {}
    for j in range(2*n - 1):
        heights = input().split()
        for h in heights:
            if int(h) in ints:
                ints[int(h)] += 1
            else: 
                ints[int(h)] = 1

    soln = []
    for key in ints:
        if ints[key] % 2 != 0:
            soln.append(key)

    soln.sort()
    s = ''

    for a in soln:
        s += str(a)
        s += ' '
        

    print("Case #{}: {}".format(i, s))
