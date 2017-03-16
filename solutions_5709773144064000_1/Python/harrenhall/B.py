#!/usr/bin/python

def solve():
	(c,f,x) = raw_input().split()
	c,f,x = float(c),float(f),float(x)
	rate = 2.0
	time_spend = 0.0
	
	while True:
		time_without = x/rate
		time_with = c/rate + x/(rate+f)
		
		if time_without <= time_with:
			return time_spend + time_without
			
		time_spend += c/rate
		rate += f
		
	
	

cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    
    d = solve()
    print d
    
