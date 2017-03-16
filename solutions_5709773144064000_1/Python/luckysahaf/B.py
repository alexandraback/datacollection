

if __name__ == '__main__':
	a = int(raw_input())
	for i in range(0,a):
		b = raw_input()
		b = b.replace('\n','')
		C,F,X = b.split(' ')
		C = float(C)
		F = float(F)
		X = float(X)
		time = 0.0
		current_cookies = 0.0
		current_rate = 2.0
		current_time = X/current_rate
		buy_time = X/(current_rate + F) + C/current_rate
		while current_time > buy_time:
			time += C/current_rate
			current_rate += F
			current_time = X/current_rate
			buy_time = X/(current_rate + F) + C/current_rate
		time += current_time
		print "Case #%i: %f" % (i+1,time)