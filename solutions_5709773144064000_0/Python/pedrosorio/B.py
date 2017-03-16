def get_next_farm_time(C, rate, secs):
	return C/rate + secs

def get_goal(X, rate, secs):
	return X/rate + secs

def get_goal_with_farm(X, C, F, rate, secs):
	return get_goal(X, rate+F, get_next_farm_time(C, rate, secs))

T = int(raw_input())
for case in xrange(1,T+1):
	C,F,X = map(float, raw_input().split())
	secs = 0.0
	rate = 2.0
	while get_goal(X, rate, secs) > get_goal_with_farm(X, C, F, rate, secs):
		secs = get_next_farm_time(C, rate, secs)
		rate += F
	print 'Case #' + str(case) + ': ' + str(get_goal(X, rate, secs))