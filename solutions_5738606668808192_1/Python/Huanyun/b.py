
digits = 32
max_count = 500
count = 0

def writeout(nums):

	global count

	ret = "1"
	for num in nums:
		if num == 1:
			ret+="11"
		else:
			ret+="00"
	ret+="1"
	div = ["3 4 5 6 7 8 9 10 11"]
	print (ret+" "+" ".join(div))
	count += 1

def dfs(nums):

	if count >= max_count:
		return

	if len(nums) == 15:
		writeout(nums)

	else:
		nums.append(0)
		dfs(nums)
		del nums[-1]
		nums.append(1)
		dfs(nums)
		del nums[-1]

print("Case #1:")
dfs([])
