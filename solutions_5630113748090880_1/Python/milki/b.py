from collections import defaultdict

def main():
    T = int(raw_input())
    for i in xrange(T):
        N = int(raw_input())
        l = []
        nums = defaultdict(int)
        for n in range(2*N-1):
        	l.append(map(int, raw_input().split()))
        	for _ in l[-1]:
        		nums[_] += 1
        ret = []
        for n in sorted(nums.keys()):
        	if nums[n] % 2 != 0:
        		ret.append(n)
        output(i, sorted(ret))

def output(casenum, ret):
    print 'Case #%d: %s' % (casenum + 1, ' '.join(map(str, ret)))


main()
