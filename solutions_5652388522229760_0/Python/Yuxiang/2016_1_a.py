
t = input()

cases = []
for i in range(t):
    cases.append(int(input()))
    
for index, n in enumerate(cases):
    if n == 0:
        print("Case #{}: {}".format(index + 1, "INSOMNIA"))
    else:
        val = 0
        d = {}
        while True:
            val += n
            for number in str(val):
                if number in d:
                    pass
                else:
                    d[number] = True
            if len(d) == 10:
                break
        print("Case #{}: {}".format(index + 1, val))


