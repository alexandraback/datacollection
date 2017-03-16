import string


nums = ("ZERO", "ONE", "TWO",
        "THREE", "FOUR", "FIVE",
        "SIX", "SEVEN", "EIGHT", "NINE")

def gao():
    for c in string.ascii_uppercase:
        s = [n for n in nums if c in n]
        if s:
            print(c, s)


from collections import Counter

def avaliable(cnt, i):
    return all(cnt[n] > 0 for n in nums[i])

def sol():
    cnt = Counter()
    s = input()
    for c in s:
        cnt[c] += 1
    ans = []
    for tp in [(0,2,4,6,8), (3,5,7), (1, 9)]:
        updated = True
        while updated:
            updated = False
            for i in tp:
                if avaliable(cnt, i):
                    updated = True
                    ans.append(i)
                    for n in nums[i]:
                        cnt[n] -= 1
    ans.sort()
    return ''.join([str(a) for a in ans])

# gao()

t = int(input())
for i in range(t):
    print("Case #%s: %s" % (i+1, sol()))
