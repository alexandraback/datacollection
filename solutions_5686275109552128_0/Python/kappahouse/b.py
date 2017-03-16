# B. Infinite House of Pancakes

t = input()
for c in range(t):
    d = input()
    p = sorted([int(s) for s in raw_input().rstrip().split(' ')])
    ret = max(p)
    for target in range(1, max(p)):
        ret = min(ret, target + sum([(i - 1) / target for i in p]))
    print "Case #" + str(c + 1) + ":", ret
