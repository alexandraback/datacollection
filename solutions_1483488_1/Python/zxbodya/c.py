__author__ = 'z_bodya'

def ilen(a):
    r = 0
    while a > 0:
        a /= 10
        r += 1
    return r

nums = {}

def fill_nums():
    a,b = 1,2000000
    for i in range(a, b):
        l = ilen(i) - 1
        t = i
        nums[i] = set()
        for j in range(l):
            t = (t % 10) * (10 ** l) + t / 10
            if (i < t) and (t <= b):
                nums[i].add(t)

fill_nums()

def solve(a, b):
    ans = 0
    for i in range(a, b):
        for t in nums[i]:
            if t <= b:
                ans += 1
    return ans

mem = {(100, 999): 801, (10000, 99999): 161982, (1, 9): 0, (100000, 999999): 2023578, (10, 99): 36, (1000, 9999): 12060,
       (1000000, 9999999): 0}

def fill_mem():
    for i in range(6):
        a = 10 ** i
        b = 10 ** (i + 1) - 1
        mem[(a, b)] = solve(a, b)
    print mem


def psolve(a, b):
    ans = 0
    for s1, s2 in mem:
        if a <= s1 and b >= s2:
            ans += mem[(s1, s2)]
            continue
        if a > s1 and b >= s2:
            ans += solve(a, s2)
            continue
        if a <= s1 and b < s2:
            ans += solve(s1, b)
            continue
        if a > s1 and b < s2:
            ans += solve(a, b)
    return ans

f = open('C-large.in', 'r')
#f = open('c_in.txt', 'r')
#f = open('C-small-attempt0.in', 'r')
o = open('c_out.txt', 'w')
t = int(f.readline())
for test in range(t):
    a, b = [int(i) for i in f.readline().split(' ')]
    o.write('Case #' + str(test + 1) + ': ')
    ans = psolve(a, b)
    o.write(str(ans) + "\n")
f.close()
o.close()