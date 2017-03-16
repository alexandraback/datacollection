
def get_ceil(K,C):
	if K%C==0:
		return K/C;
	return K/C+1;
T = input();

for Ti in range(T):
	line = raw_input();
	#print(line); 
	[K,C,S] = map(int, line.split());
	num = get_ceil(K,C);
	if S<num:
		ans = "IMPOSSIBLE";
		print("Case #{0}: {1}".format(Ti+1,ans));
		continue;
		
	print("Case #{0}: ".format(Ti+1)),
	for j in range(num):
		ans = 0;
		for k in range(C):
			if j*C+k>=K:
				break;
			ans *= K;
			ans += j*C+k;
		
		print(" {0}".format(ans+1)),
	print("");
