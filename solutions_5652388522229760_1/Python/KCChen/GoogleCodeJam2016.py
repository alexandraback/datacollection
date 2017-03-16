
# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    n = int(raw_input())  # read a list of integers, 2 in this case
    digit_set=set([])
    multiplier=1
    if n==0:
        print "Case #{}: {}".format(i,'INSOMNIA')
    else:
        while True:
	    tmp=n*multiplier
	    digit_set.update(set(str(tmp)))
		#print digit_set
		
	    if len(digit_set)==10:
	        print "Case #{}: {}".format(i,tmp)
		break
	    multiplier +=1


