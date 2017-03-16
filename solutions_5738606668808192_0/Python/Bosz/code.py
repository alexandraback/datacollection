import gmpy2

def primes2(table=None):

    def sieve(limit):
        sieve_limit = gmpy2.isqrt(limit) + 1
        limit += 1
        bitmap = gmpy2.xmpz(3)
        bitmap[4 : limit : 2] = -1
        for p in bitmap.iter_clear(3, sieve_limit):
            bitmap[p*p : limit : p+p] = -1
        return bitmap

    table_limit=1000000
    if table is None:
        table = sieve(table_limit)

    for n in table.iter_clear(2, table_limit):
        yield n

    n = table_limit
    while True:
        n = gmpy2.next_prime(n)
        yield n


def check(base):
        global prime_list
	prime_trigger =0
	list2to10 =[]
	for i in range(2,11):
		cbase = int(base,i)
                if(cbase in prime_list):
                    #print '{} is a prime'.format(cbase)
                    return 0
	#print '{} is not a prime'.format(base)	
	for i in range(2,11):
		cbase = int(base,i)
		#print 'something if {} with {} to {} is correct'.format(base,i,cbase)
		x = checkPrime(cbase)
		if (x==1) :
			prime_trigger=1
			return 0
		list2to10.append(x)
	listprint = ''.join([str(x)+' ' for x in list2to10])
	print '{} {}'.format(base,listprint)
	return 1
	
	
			


def re_create_coin(current,N,J):
	global count
	if(count==J): return 
	if(len(current)==N):
                #print current
		count +=check(current)
		return
	if(len(current)==0 or len(current)==N-1):
		re_create_coin(current+'1',N,J)
	else:
		re_create_coin(current+'0',N,J)
		re_create_coin(current+'1',N,J)
		
		
def checkPrime(num):
	global prime_list
	for i in xrange(0,len(prime_list)):
            if(num%prime_list[i]==0):
                #print prime_list[i]
                return prime_list[i]
        return 1


T = int(raw_input())
count=0
prime_list=[]
limit= 1000000
for case in range(1,T+1):
	N,J = [int(s) for s in raw_input().split(' ')]
	count=0
	strnum=''
        #print str(bin(57))[-3:]
        #print str(bin(55))[-3:]
	for i in range(0,N):
            strnum+='1'
        maxnum= int(strnum)
        #print maxnum
        strnum='1'
        for i in range(1,N-1):
             strnum+='0'
        strnum+='1'
        current = strnum
        prime_num_gen=primes2()
        for i in prime_num_gen:
            if(i<=maxnum and i <=limit):
                prime_list.append(i)
            else : break
        
        #print 'finish create prime under {}'.format(maxnum)
        print 'Case #{}:'.format(case)
	re_create_coin('',N,J)
