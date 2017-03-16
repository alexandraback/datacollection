t = int(raw_input())
for ca in range(t):
    [mote, rest] = [int(i) for i in raw_input().split(' ')]
    nums = [int(i) for i in raw_input().split(' ')]
    nums.sort()
    minops = 10000000
    ops = 0
    if mote == 1:
        minops = rest
    else:
        for k in nums:
            minops = min(minops, ops + rest)
            rest -= 1
            if mote > k:
                mote += k
            else:
                while mote <= k:
                    mote += mote - 1
                    ops += 1
                mote += k
        minops = min(minops, ops)

    print "Case #{0}: {1}".format(ca + 1, minops)

