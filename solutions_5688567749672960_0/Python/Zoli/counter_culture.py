LIMIT = 10**6
answer = [float('inf')] * (LIMIT+7)

answer[0] = 0
for i in range(1, LIMIT+3):
	answer[i] = min(answer[i], answer[i-1]+1)
	try:
		index = int(str(i)[::-1])
		answer[index] = min(answer[index], answer[index-1]+1+1, answer[i]+1)
	except IndexError:
		pass

#print(answer[:30])

t = int(input())
for i in range(t):
	n = int(input())
	print('Case #{}: {}'.format(str(i+1), str(answer[n])))