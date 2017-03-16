# Im stupid, so brute force

def digits(num):
    if num == 0:
        return set([0])
    ret = []
    while num > 0:
        ret.append(num % 10)
        num /= 10
    return set(ret)

def process_num(c, num):
    if num == 0:
        print("Case #%d: INSOMNIA" % c)
    else:
        d = set(range(0, 10))
        l = num
        d -= digits(l)
        while (len(d) > 0):
            l += num
            d -= digits(l)
        print("Case #%d: %d" % (c, l))

N = int(raw_input())
for n in range(1, N+1):
    num = int(raw_input())
    process_num(n, num)
'''
for num in range(0, 1000000):
    process_num(num, num)
'''
