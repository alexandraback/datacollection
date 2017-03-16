from collections import defaultdict

letters = {0:"ZERO", 1:"ONE", 2:"TWO", 3:"THREE", 4:"FOUR", 5:"FIVE", 6:"SIX", 7:"SEVEN", 8:"EIGHT", 9:"NINE"}

def helper(res, d, l, digit):
    global letters
    while d[l] > 0:
        res.append(digit)
        for c in letters[digit]:
            d[c] -= 1

def solve(s):
    d = defaultdict(int)
    for c in s:
        d[c] += 1
    res = list()
    helper(res, d, 'Z', 0)
    helper(res, d, 'W', 2)
    helper(res, d, 'X', 6)
    helper(res, d, 'G', 8)
    helper(res, d, 'T', 3)
    helper(res, d, 'R', 4)
    helper(res, d, 'F', 5)
    helper(res, d, 'V', 7)
    helper(res, d, 'O', 1)
    helper(res, d, 'N', 9)
    return ''.join(map(str,sorted(list(res))))

t = int(input())
for i in range(t):
	tc = input()
	sol = solve(tc)
	print('Case #{}: {}'.format(i+1, sol))

