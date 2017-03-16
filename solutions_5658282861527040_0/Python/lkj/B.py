t = int(input())
for tc in range(1, t+1):
# 0 <= v1 < a
# 0 <= v2 < b
#catalina buys all numbers 0 <= n < k
#question: how many pairs (v1, v2) that 0 <= v1 & v2 < k
    (a, b, k) = [int(x) for x in input().split()]
    
#basenum: up to k, all possibilities give a winner number
    basenum = min(a, k) * min(b, k)

#additional 1: one of them above k and the other below is also good
    if a > k:
        basenum += (a-k)*k
    if b > k:
        basenum += (b-k)*k

#additional 2: the hard part: both numbers >= k but shared bits not

# 0 0 1 1 0 1 1 0
# 2 0 3 0 2 1 3 1
# 0 2 0 3 0 4 1 2 1 3 1 4

# 3 4 2 4
    if a > k and b > k:
        for i in range(k, a):
            for j in range(k, b):
                if i&j < k:
                    basenum += 1

    print('Case #%i: %i' % (tc, basenum))
