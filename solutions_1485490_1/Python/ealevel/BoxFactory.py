class Object:
	def __init__(self, quantity, type):
		self.quantity = quantity
		self.type = type
	
	def __str__(self):
		return "{0}x{1}".format(self.type, self.quantity)

def dp_fun(n, qn, m, qm):
	if (n, qn, m, qm) in dp:
		return dp[n, qn, m, qm]

	if n == N or m == M:
		return 0
	if qn == 0:
		return dp_fun(n+1, boxes[n+1].quantity if n+1 != N else None, m, qm)
	if qm == 0:
		return dp_fun(n, qn, m+1, toys[m+1].quantity if m+1 != M else None)

	if boxes[n].type == toys[m].type:
		dp[n, qn, m, qm] = min(qn, qm) + dp_fun(n, qn - min(qn, qm), m, qm - min(qn, qm))
	else:
		dp[n, qn, m, qm] = max(dp_fun(n+1, boxes[n+1].quantity if n+1 != N else None, m, qm), dp_fun(n, qn, m+1, toys[m+1].quantity if m+1 != M else None))
	return dp[n, qn, m, qm]

T = int(raw_input())
for t in range(1, T+1):
	N, M = map(int, raw_input().split())
	line1 = map(int, raw_input().split())
	line2 = map(int, raw_input().split())
	boxes = []
	toys = []
	dp = {}
	for i in range(0, 2*N, 2):
		boxes.append(Object(line1[i], line1[i+1]))
	for i in range(0, 2*M, 2):
		toys.append(Object(line2[i], line2[i+1]))
	print "Case #{0}: {1}".format(t, dp_fun(0, boxes[0].quantity, 0, toys[0].quantity))
