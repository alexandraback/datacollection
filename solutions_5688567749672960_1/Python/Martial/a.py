import sys
sys.stdin = open('A-large.in')
sys.stdout = open('out.txt', 'w')

def check(n):

    d = {1:1}
    done = {}
    s = set([1])
    for i in range(n):
        next_s = set()
        # print(i+1,'\t', len(d),'\t', sorted(s))
        for j in s:
            dd = d[j]

            jj = j+1
            if jj not in d:
                next_s.add(jj)
                d[jj] = dd+1

            digits = list(str(j))
            digits.reverse()
            jj = int(''.join(digits))
            if jj not in d:
                next_s.add(jj)
                d[jj] = dd+1

            done[j] = True

        s = next_s

    return d

#keys = sorted(list(d.keys()))
#for key in keys:
#    print(key,'\t',d[key])

n= 3436
d = check(n)
# for i in range(7):
#    print(d[10**i])


def solve(n):
    if n<=19:
        return n
    res = 10
    for i in range(1,20):
        if n == 10 ** i:
            return res
        res += 10 ** ((i+1)//2)
        res += -1
        res += 10 ** ((i+1)//2 + (i+1)%2)

    if n % 10 == 0:
        return solve(n-1)+1

    digits = list(str(n))
    nd = len(digits)
    tmp = solve(10 ** (nd-1))
    res = tmp + n - 10 ** (nd-1)

    h = nd // 2
    s = digits[:h]
    s.reverse()
    a = int(''.join(s))
    b = int(''.join(digits[h:]))
    res = min(res, tmp + a+b)
    return res

def check2():
    for i in range(17):
        n = 10**i
        print(n, solve(n))

#check2()

# for i in range(1, 100000):
#     if d[i] != solve(i):
#        print(i, d[i], solve(i))






n_cases = int(input())
for case in range(n_cases):
    i = int(input())
#    res = d[i]
    res = solve(i)
    print('Case #{}: {}'.format(case+1, res))

