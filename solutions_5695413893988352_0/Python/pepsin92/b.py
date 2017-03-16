from itertools import product

def transform(nums, s):
    s = s.format(*nums)    
    n = len(s)//2
    a, b = s[:n], s[n:]
    c, d = int(a), int(b)
    return [abs(c - d), d, c, a+' '+b]


t = int(input().strip())
for tc in range(1, t+1):
    a = input().replace(' ', '')
    num = a.count('?')
    a = a.replace('?', '{}')
    res = min([transform(x, a) for x in product('0123456789', repeat=num)])

    # print(filter(lambda x, y: y=='023 023', res))

    print("Case #{}: {}".format(tc, res[3]))
