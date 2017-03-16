from operator import mul

tests = int(raw_input())
for test in xrange(1, tests + 1):
	a, b = map(int, raw_input().split())
	p = map(float, raw_input().split())
	p = [1.0] + p
	
	got_it_wrong = 1 - reduce(mul, p)
	keep_typing = (b - a + 1) + got_it_wrong * (b + 1)
	optimal_strategy = keep_typing
	
	for backspaces in xrange(1, a + 1):
		got_firsts_wrong = 1 - reduce(mul, p[:a-backspaces+1])
		press_backspace = backspaces + (b - (a - backspaces) + 1) + got_firsts_wrong * (b + 1)
		optimal_strategy = min(optimal_strategy, press_backspace)
	
	optimal_strategy = min(optimal_strategy, b + 2)
	
	print 'Case #%d: %f' % (test, optimal_strategy)