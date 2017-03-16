import sys 
T=0
T_cnt=0
D=0
Pi=[]
case_num=0
def cnt_change(Pi):
	cost=[]
	max_value=max(Pi)
	for i in range(1, max_value+1):
		cnt=0
		for j in Pi:
			if j % i == 0:
				cnt += j / i -1
			else:
				cnt += j / i
		cost+=[cnt+i]
	return min(cost)

for line in sys.stdin:
	if T == 0:
		T = int(line.split('\n')[0])
	else:
		cnt=0
		T_cnt += 1
		if T_cnt%2 == 1:
			D = int(line.split('\n')[0])
		else:
			case_num+=1
			Pi = line.split('\n')[0].split(' ')
			Pi = map(int, Pi)
			print "Case #{0}: {1}".format(str(case_num), str(cnt_change(Pi)))


				