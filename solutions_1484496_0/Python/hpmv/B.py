import string
T = int(raw_input())
for casenum in range(T):
    line = raw_input().split()
    N = int(line[0])
    nums = [int(line[i+1]) for i in range(N)]
    sums = {0:[]}
    for i in range(N):
        num = nums[i]
        new = {}
        for sum in sums.iterkeys():
            seq = sums[sum]
            new[sum] = seq
            new[sum+num]= seq+[i+1]
            new[sum-num]= seq+[-i-1]
        sums = new
        #print sums
    print "Case #%s:"%(casenum+1)
    for sum in sums.iterkeys():
        seq = sums[sum]
        if sum==0:
            print string.join([str(nums[s-1]) for s in seq if s>0],' ')
            print string.join([str(nums[-s-1]) for s in seq if s<0], ' ')
            break
    else:
        print 'Impossible'
        
