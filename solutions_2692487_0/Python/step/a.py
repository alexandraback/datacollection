import os,sys,fileinput

def getline():
	R= sys.stdin.readline()
	R = R.replace("\n","")
	R = R.replace("\r","")
	return R

T = int(getline())

cache = {}

def examine(A, motes):
	global cache
	if len(motes) == 0:
		return 0
	key = str((A,motes))
	if 0:
		print(key)
	if key in cache:
		return cache[key]
	if 0:
		print("Examine(" + str(A) + " " + str(motes))
	lower_motes = [ x for x in motes if x < A ]
	other_motes = [ x for x in motes if x >= A ]

	if len(lower_motes) > 0:
		A += sum(lower_motes)
		return examine( A, other_motes )
	assert len(lower_motes) == 0
	R2 = examine(A, motes[:-1])
	if A != 2*A-1:
		R1 = examine(2*A-1, motes)
	else:
		R1 = 999999999999999

	R = 1 + min( R1, R2 )
	cache[key] = R
	return R

for t in range(T):
	(A,N) = [ int(x) for x in getline().split() ]
	motes = [ int(x) for x in getline().split() ]
	motes.sort()
	cache = {}
	if 0:
		print("A:%d N:%d" % (A,N))
		print(motes)
	result = examine( A , motes )
	
	print ( "Case #%d: %d" % ( t+1, result) )
