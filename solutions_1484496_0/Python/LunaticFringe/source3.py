def solve(x):
	x = x.split('\n')
	tests = int(x[0])
	for i in range(1, tests+1):
		print 'Case #%s:' % i
		print getAnswer(map(int, x[i].split()[1:]))

def getAnswer(nums, index=0, sum=0, curList=None, memo=None):
	if index==len(nums): return
	if curList is None: curList = []
	if memo is None: memo = {}
	x=nums[index]
	curList.append(str(x))
	sum += x
	text = ' '.join(curList)
	if sum in memo: return '%s\n%s' % (memo[sum], text)
	memo[sum] = text
	answer = getAnswer(nums, index+1, sum, curList, memo)
	curList.pop()
	if answer: return answer
	return getAnswer(nums, index+1, sum-x, curList, memo)

# then i run solve() against the input string and paste the output into a new file