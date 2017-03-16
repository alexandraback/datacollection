

import sys

mulsarr = { 1:{ 1:[False,1],'i':[False,'i'],'j':[False,'j'],'k':[False,'k']},
'i':{ 1:[False,'i'],'i':[True,1]   ,'j':[False,'k'],'k':[True,'j']},
'j':{ 1:[False,'j'],'i':[True,'k'] ,'j':[True,1]   ,'k':[False,'i']},
'k':{ 1:[False,'k'],'i':[False,'j'],'j':[True,'i'] ,'k':[True,1]}}

def quaternmul( a, b ):

	r = list(mulsarr[a[1]][b[1]])
	r[0] = ( r[0] + a[0] + b[0] ) % 2
	return r


def JfromStarts( S, starts ):

	ends = set()
	curr = [False,1]


	for start in starts:
		# print start
		if start == len(S)-1:
			continue
		for i in range(start+1,len(S)):
			curr = quaternmul(curr, [False, S[i]])
			# print i,x, curr
			if curr == [False,'j']:
				# print start+1+i
				ends.add(i)

	return ends

def JfromStartsTo( S, starts, k ):

	ends = set()
	curr = [False,1]


	for start in starts:
		# print start
		curr = [False,1]
		if start == len(S)-1:
			continue
		for i in range(start+1,k):
			curr = quaternmul(curr, [False, S[i]])
			# print i,x, curr
		if curr == [False,'j']:
			return True

	return False

def IfromLeft( S ):

	l = []
	curr = [False,1]

	for i,x in enumerate(S):
		curr = quaternmul(curr, [False,x])
		if curr == [False,'i']:
			l.append(i)

	return l
			
def KfromRight( S ):

	l = []
	curr = [False,1]

	S = S[::-1]

	for i,x in enumerate(S):
		curr = quaternmul( [False,x], curr )
		# print i, x, curr, 'k'
		if curr == [False,'k']:
			l.append(len(S)-i-1)

	S = S[::-1]
	return l
			

# def KfromRightAndCheck( S, jjs ):
# 	curr = [False,1]

# 	S = S[::-1]

# 	for i,x in enumerate(S):
# 		curr = quaternmul( [False,x], curr )
# 		# print i, x, curr, 'k'
# 		if curr == [False,'k']:
# 			if (len(S)-i-1) - 1 in jjs:
# 				return True

# 	return False 

def Kshortcuts( S, kk ):
	kk = kk[::-1]

	cuts = dict()

	for i in range(len(kk)-1):

		curr = [False,1]
		start = kk[i]
		stop = kk[i+1]
		while start < stop:
			curr = quaternmul( curr, [False,S[start]])
			start += 1

		cuts[(kk[i],kk[i+1])] = curr

	return cuts



def brutenforsen( S, L, X ):

	ss = S*X

	ii = IfromLeft( ss )
	if len(ii) == 0:
		return False

	kk = KfromRight( ss )
	if len(kk) == 0:
		return False


	jjs = JfromStartsTo( ss, ii, kk[0] )

	# print len(ss), len(ii), len(kk), len(jjs)
	# print ss
	# print ii
	# print kk
	# print Kshortcuts( ss, kk )
	# # print jjs

	# for x in kk:
	# 	if x-1 in jjs:
	# 		# print x
	# 		return True

	# return False

	return jjs

def Calk(S,L,X):
	
	if L*X < 3:
		return "NO"

	if brutenforsen(S,L,X):
		return "YES"
	else:
		return "NO"

if __name__ == '__main__':
	
	f = open(sys.argv[1])

	t = int(f.readline())

	for i in range(t):

		[L,X] = [ int(x) for x in f.readline().split(" ") ]

		S = f.readline().split()[0]

		print( "Case #%d: %s" % ( (i+1), Calk(S,L,X) ) )