import sys

kase = int(sys.stdin.readline())

def test(nums,K):

	# print(nums)
	if (len(nums) == 0):
		return []
	elif (len(nums)==1):
		return [str(nums[0])]
	else:
		num = nums[0]
		for i in range(1,len(nums)):
			num = (num-1)*K + nums[i]
		return [str(num)]


for k in range(kase):
	line = sys.stdin.readline()
	line = line.split()
	K,C,S = int(line[0]), int(line[1]), int(line[2])

	head = "Case #"+str(k+1)+": "

	need = K/C
	if K%C != 0:
		need += 1

	if need > S:
		print(head+"IMPOSSIBLE")
		continue

	i = 1
	ret = [] 
	while (i <= K):
		ret += test(range(i,min(K+1,i+C)),K)
		i += C

	print(head+" ".join(ret))


