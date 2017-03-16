from collections import Counter

T = int(input())
nums = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
cnums = {}
for i, num in enumerate(nums):
    cnums[i] = Counter(num)
for t in range(1, T + 1):
    print('Case #%d: ' % t, end='')
    s = input()
    cs = Counter(s)
    ans = []
    for i in [0, 2, 4, 6, 7, 8, 3, 5, 1, 9]:
        while True:
            for j, jj in cnums[i].items():
                if jj > cs[j]:
                    break
            else:
                for j, jj in cnums[i].items():
                    cs[j] -= jj
                ans.append(str(i))
                continue
            break
    print(''.join(sorted(ans)))
