import sys

cases = int(raw_input())

inf = 1000010

answer = [inf for k in range(1000010)]

def reverse(k):
	r = 0
	while k > 0:
		r *= 10
		r += (k%10)
		k /= 10
	return r

answer[1] = 1
for k in range(1, 1000003):
	answer[k+1] = min(answer[k+1], answer[k]+1)
	r = reverse(k)
	if r <= 1000000:
		answer[r] = min(answer[r], answer[k]+1)

for current_case in range(1, cases+1):
	N = int(raw_input())
	
	ans = answer[N]
	
	print "Case #%d: %d" % (current_case, ans)