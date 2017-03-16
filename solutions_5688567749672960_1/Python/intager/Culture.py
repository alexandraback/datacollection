import os, time, sys
sys.setrecursionlimit(1800000)
cur_dir=os.path.dirname( os.path.abspath(__file__) )
output=open( os.path.join( cur_dir, 'output.txt' ), 'w' )

def log( msg ):
    print msg
    output.write( msg + '\n' )

lines=[]
for f in os.listdir( cur_dir ):
    if f.lower().endswith( '.in' ):
        lines=open( os.path.join( cur_dir, f ), 'r' ).readlines()
        break

# ------------------------------------------------------- 

def greedy2( n ):
	tot=1

	#print '\t greedy2( %d )' % n

	while n>1:
		#print 'n=', n

		a=n-1
		b=n+5

		s=str(n)

		left=len(s)/2
		right=len(s)-left
		f=s[:left] + '0'*(right-1) + '1'

		val=int(f)
		b=int( f[::-1] )
		#print 'val=', val

		if val<a:
			#print 'f=', f, 'inc=', n-val
			tot+=n-val
			b=int( f[::-1] )
			if b!=val: tot+=1
			n=b
		else:
			n=a
			tot+=1
		
	#print 'greed = %d' % tot
	return tot

def greedy( n ):
	tot=1
	while n>1:
		a=n-1

		b=n+5

		s=str(n)
		if len(s)<=3 and s[-1] == '1':
			b=int( s[::-1] )
		if len(s)>3 and s[-2:] == '01':
			b=int( s[::-1] )

		if a<b:
			n=a
		else:
			n=b

		tot+=1
		#print n,
	return tot

def recon( k ):
	print 'recon:',
	while k>1:
		print k,
		if k-1 != prev[k]: print '*',
		k=prev[k]
	print
	return 0

#LIM=10**6 + 1
LIM=10**5 + 2
best=[ LIM ] * LIM
prev=[ 0 ] * LIM

#best[1]=1
q=[ (1,1,-1) ]

while q:
	num, dist, p=q.pop(0)
	#print num, dist

	if num>=LIM: continue
	if dist>=best[num]: continue
	
	best[num]=dist
	prev[num]=p

	q.append( (num+1,dist+1,num) )

	s=str(num)[::-1]
	q.append( ( int(s),dist+1,num) )



for z in [124,455,2422,5665,12123,7654,6789,44444, LIM-1]:
	print '\t', z, best[z], greedy2(z)

print greedy2( 6789 )
print greedy2( 44444 )
print greedy2( LIM-1 )

'''
for z in range(1,10):
	t=LIM/z - 1
	print '\t', t, best[t], greedy(t)
'''

# ------------------------ main ------------------------------- 


k=1
case=1

while k<len(lines):
	d=int(lines[k].strip()); k+=1
	log( 'Case #%d: %d' % (case,greedy2(d)) )
	case+=1
