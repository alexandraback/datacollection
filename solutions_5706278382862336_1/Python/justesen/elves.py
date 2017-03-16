def remaining(num, denom):
    if num <= 0:
        return True
    while num < denom:
        next = denom // 2
        if next*2 < denom:
            return False
        denom = next
    return remaining(num-denom,denom)

def ancestor(num, denom):
    gen = 0
    while num < denom:
        gen += 1
        next = denom // 2
        if next*2 < denom:
            return "impossible"
        denom = next
    if remaining(num-denom,denom):
        return str(gen)
    else:
        return "impossible"

cases = int(input())
for i in range(1, cases+1):
    conf = list(map(int, input().split('/')))
    p = conf[0]
    q = conf[1]
    res = ancestor(p, q)
    print("Case #" + str(i) + ": " + str(res))
