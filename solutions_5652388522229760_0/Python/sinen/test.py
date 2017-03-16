f = open("out.txt", "w")	

def check(arr) :
	ok = True
	for x in arr :
		if x == False :
			ok = False
	return ok

def solve(n) :
	if n == 0 : return -1
	vis = [False for i in range(10)]
	tmp = 0
	cur = n
	while cur > 0 :
		vis[cur % 10] = True
		cur = cur // 10
	while not check(vis) :
		tmp += n
		cur = tmp
		while cur > 0 :
			vis[cur % 10] = True
#			print(cur)
			cur = cur // 10
#		print(vis)	
	return tmp

n = int(input())

for tc in range(1, n + 1) :
	ans = solve(int(input()))
	f.write("Case #{}: ".format(tc))
	if ans == -1 :
		f.write("INSOMNIA\n")
	else :
		f.write("{}\n".format(ans))
		
f.close()