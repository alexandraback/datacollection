t = int(raw_input())
for _ in xrange(t):
	print 'Case #'+str(_+1)+":",
	# arr = map(int,raw_input().split())
	s = raw_input()
	arr = [0]*26
	for ch in s :
		arr[ord(ch)-65] += 1;
	nums = [0]*10
	
	if arr[25] != 0 :
		nums[0]+=arr[25]
		arr[4] -= arr[25]
		arr[ord('R')-65] -= arr[25]
		arr[ord('O')-65] -= arr[25]
		arr[ord('Z')-65] -= arr[25]
	if arr[23] != 0 :
		nums[6] += arr[23]
		arr[ord('S')-65] -= arr[23]
		arr[ord('I')-65] -= arr[23]
		arr[ord('X')-65] -= arr[23]
	if arr[6] != 0 :
		nums[8] += arr[6]
		arr[ord('E')-65] -= arr[6]
		arr[ord('I')-65] -= arr[6]
		arr[ord('H')-65] -= arr[6]
		arr[ord('T')-65] -= arr[6]
		arr[ord('G')-65] -= arr[6]
	if arr[ord('W')-65] != 0 :
		nums[2] += arr[22]
		arr[ord('T')-65] -= arr[22]
		arr[ord('O')-65] -= arr[22]
		arr[ord('W')-65] -= arr[22]
	if arr[ord('U')-65] != 0 :
		nums[4] += arr[20]
		arr[ord('F')-65] -= arr[20]
		arr[ord('O')-65] -= arr[20]
		arr[ord('R')-65] -= arr[20]
		arr[ord('U')-65] -= arr[20]
	if arr[14] != 0 :
		nums[1] += arr[14]
		arr[ord('N')-65] -= arr[14]
		arr[ord('E')-65] -= arr[14]
		arr[ord('O')-65] -= arr[14]
	if arr[ord('F')-65] != 0 :
		nums[5] += arr[5]
		arr[ord('E')-65] -= arr[5]
		arr[ord('V')-65] -= arr[5]
		arr[ord('I')-65] -= arr[5]
		arr[ord('F')-65] -= arr[5]
	if arr[ord('V')-65] != 0 :
		nums[7] += arr[21]
		arr[ord('E')-65] -= arr[21]
		arr[ord('E')-65] -= arr[21]
		arr[ord('S')-65] -= arr[21]
		arr[ord('N')-65] -= arr[21]
		arr[ord('V')-65] -= arr[21]
	if arr[ord('I')-65] != 0 :
		nums[9] += arr[8]
		arr[ord('E')-65] -= arr[8]
		arr[ord('N')-65] -= arr[8]
		arr[ord('N')-65] -= arr[8]
		arr[ord('I')-65] -= arr[8]
	nums[3] += arr[19]
	# print nums;
	ans = ''
	for i in range(10) :
		a = nums[i]
		for j in xrange(a):
			ans += str(i)
	print ans;