with open('C-small-attempt0.in') as f:
    with open('c.out', 'w') as out:
        cases = f.readline()
        cases = int(cases)
        for i in xrange(1, cases+1):
            [C, D, V] = map(lambda x: int(x), f.readline().split(' '))
            denom = map(lambda x: int(x), f.readline().split(' '))
            denom.sort()
            denom.reverse()
            res = 0
            def split(num, nums):
                if not nums and num:
                    return False
                for k in range(len(nums)):
                    if num-nums[k] == 0:
                        return True
                    elif split(num-nums[k], nums[k+1:]):
                        return True
                return False
            for j in range(1, V+1):
                if not split(j, filter(lambda x: x <= j, denom)):
                    denom.append(j)
                    res += 1
                    denom.sort()
                    denom.reverse()
            print 'Case #{i}: {res}'.format(res=res, i=i)
            out.write('Case #{i}: {res}\n'.format(res=res, i=i))