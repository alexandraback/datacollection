T = int(raw_input())
for tc in xrange(1, T + 1):
    S = raw_input()
    nums = [0] * 10
    nums[0] = S.count('Z')
    nums[2] = S.count('W')
    nums[4] = S.count('U')
    nums[6] = S.count('X')
    nums[8] = S.count('G')
    nums[7] = S.count('S') - nums[6]
    nums[3] = S.count('R') - (nums[0] + nums[4])
    nums[1] = S.count('O') - (nums[0] + nums[2] + nums[4])
    nums[9] = (S.count('N') - (nums[1] + nums[7])) / 2
    nums[5] = S.count('F') - nums[4]
    answer = ''.join(str(i) * nums[i] for i in xrange(10))
    print 'Case #{}: {}'.format(tc, answer)

