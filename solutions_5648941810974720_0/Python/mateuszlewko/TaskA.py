t = int(raw_input())
nums = ['ZERO', 'EIGHT', 'SIX', 'SEVEN', 'FIVE', 'TWO', 'FOUR', 'ONE', 'NINE', 'THREE']
vals = [0, 8, 6, 7, 5, 2, 4, 1, 9, 3]

for i in xrange(1, t + 1):
    res = []
    s = raw_input()
    cnt = {}

    for l in s:
        cnt[l] = cnt.get(l, 0) + 1

    ind = 0
    while ind < 10:
        remove = True
        for l in nums[ind]:
            cnt[l] = cnt.get(l, 0) - 1
            if cnt[l] < 0:
                remove = False

        if not remove:
            for l in nums[ind]:
                cnt[l] += 1
            ind += 1
        else:
            res.append(vals[ind])

    print 'Case #' + str(i) + ':', ''.join(str(x) for x in sorted(res))
