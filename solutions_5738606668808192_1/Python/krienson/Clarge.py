LIM = 10000005
primes = []
seen = []
def init():
	for i in xrange( LIM ):
		seen.append( False );

def sieve():
	primes.append( 2 );
	for i in xrange( 3, LIM, 2 ):
		if ( seen[ i ] == True ):
			continue
		primes.append( i )
		for j in xrange( i+i, LIM, i ):
			seen[ j ] = True
	#print( len(primes) )

def isPrime(n):
	for p in primes:
		if (n == p):
			return True
		if ((n % p) == 0 ):
			return False
		if (n < p):
			break
	return True

def getDivisor(n):
	for p in primes:
		if ((n%p)==0):
			return p
	return 0

def convert(n,base):
	res = 0
	addbase = 1
	while ( n > 0 ):
		if ((n%2) == 1 ):
			res += addbase
		addbase *= base
		n = n/2
	return res

def printBase2(n,N):
	res=""
	while (True):
		if ( (1<<N)&n ):
			res = res + "1"
		else:
			res = res + "0"
		N = N - 1
		if (N < 0):
			break
	return res


init()
sieve()
kases = int(raw_input())
for k in xrange( 1, kases+1 ):
	print("Case #%d:"%(k))
	line = raw_input().split()
	N, J = int(line[0]),int(line[1])
	fromN = 2**(N-2)
	toN = 2**(N-1)
	while( ( J > 0 ) and ( fromN < toN ) ):
		num = toN | ( fromN * 2 ) | 1
		cs = []
		ok = True
		for base in xrange(2,11):
			converted = convert( num , base )
			cs.append( converted )
			if( isPrime( converted ) == True ):
				ok = False
				break
		if ( ok == True ):
			J = J - 1
			print( printBase2( num , N-1 ) ),
			for c in cs:
				print( getDivisor( c ) ),
			print

		fromN = fromN + 1
				

