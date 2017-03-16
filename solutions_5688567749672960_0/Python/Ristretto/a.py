N=int(raw_input())
input=[]

def rev(num):
	ret=0
	while 1:
		ret+=num%10
		if num/10 == 0: break
		else:
			num /= 10
			ret *= 10
	return ret


def get(num):
	print "DEBUG: get( "+str(num)+" )"
	i=0
	while 1:
		if (10**i)>num: break
		i+=1
	s = 10**((i+1)/2)
	if num<20:
		print "DEBUG: "+str(num)
		return num
	elif num/s ==1:
		print "DEBUG: "+str(num-90)
		return get(19)+num-90
	elif num/s == 10**(i/2-1):
		print "DEBUG: "+str(num-(rev(num/s)+10**(i-1)-10**(i/2)))
		return get(rev(num/s)+10**(i-1)-10**(i/2))+num-(rev(num/s)+10**(i-1)-10**(i/2))
	elif num%s == 0:
		print "DEBUG: "+str(1)
		return get(num-1)+1
	else:
		print "DEBUG: "+str(num%s)
		return get(rev(num/s)+10**(i-1))+num%s


for i in range(N):
	input.append(int(raw_input()))

#res = list(map(get, input))

for i in range(N):
	print "Case #%d: %d" % ( i+1, get(input[i]) )
