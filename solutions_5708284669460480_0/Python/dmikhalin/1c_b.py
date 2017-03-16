input = open('B-small-attempt0.in', 'r')
output = open('B-small-attempt0.out', 'w')
t = int(input.readline().rstrip())
for test in range(t):
    k, l, s = map(int, input.readline().rstrip().split())
    keys = input.readline().rstrip()
    target = input.readline().rstrip()
    max_inc = 0
    OK = True
    for c in target:
        if c not in keys:
            OK = False
    if OK:
        step = l
        for i in range(1, l):
            if target[i:] == target[: l-i]:
                step = i
                break
        max_inc = 1 + (s - l) // step
    ans = 0    
    if max_inc > 0:
        for a1 in keys:
            for a2 in keys:
                for a3 in keys:
                    for a4 in keys:
                        for a5 in keys:
                            for a6 in keys:
                                for a7 in keys:
                                    res = a1 + a2 + a3 + a4 + a5 + a6 + a7
                                    res = res[:s]
                                    count = 0
                                    for i in range(s):
                                        if res[i:i+l] == target:
                                            count += 1
                                    ans += count
        ans /= k ** 7
    ans = max_inc - ans
    output.write("Case #" + str(test + 1) + ": " + str(ans) + "\n")

input.close()
output.close()