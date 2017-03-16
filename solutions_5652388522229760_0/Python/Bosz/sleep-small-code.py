

T = int(raw_input())
#digits = [0 for x in range(0,10)]
#print sum(digits)
for case in range(1,T+1):
	N = int(raw_input())
	digits = [0 for x in range(0,10)]
	loop_trigger =1
	counter=0
	text = 'INSOMNIA'
	before_ss=''
	while(loop_trigger==1):
		counter+=1
		ss= str(N*counter)
		if(ss==before_ss): loop_trigger=0
		for s in ss:
			digit = int(s)
			digits[digit] = 1
		if(sum(digits)==10):
			text = ss
			loop_trigger=0
		#print '{} , {}'.format(ss,digits,)
		before_ss =ss
	print 'Case #{}: {}'.format(case,text)
			
		
	
