import sys


t = int(sys.stdin.readline())

for case in xrange(1, t+1):
    print 'Case #' + str(case) + ':',
    
    n = int(sys.stdin.readline())
    nums = []
    for i in xrange(2*n - 1):
        nums.extend([int(x) for x in sys.stdin.readline().split()])
    nums = sorted(nums)
    ans = set()
    for num in nums:
        if num in ans:
            ans.discard(num)
        else:
            ans.add(num)
            
    print ' '.join([str(x) for x in sorted(ans)])
