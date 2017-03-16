import sys

cases = sys.stdin.readlines()

for i in range(1, len(cases)):
    case = list(map(int, cases[i].split()))
    N, S, p = case[:3]
    t = case[3:]
    y = 0
    for n in t:
        if n % 3 == 0:
            if n // 3 >= p:
                y += 1
            elif n > 1 and S > 0 and n // 3 + 1 >= p:
                S -= 1
                y += 1
        elif n % 3 == 1:
            if n // 3 + 1 >= p:
                y += 1
        elif n % 3 == 2:
            if n // 3 + 1 >= p:
                y += 1
            elif S > 0 and n // 3 + 2 >= p:
                S -= 1
                y += 1
    print('Case #', i, ': ', y, sep='')
