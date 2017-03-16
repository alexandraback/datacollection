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

#LIM=10**6 + 1
LIM=10**6 + 2
best=[ LIM ] * LIM

#best[1]=1
q=[ (1,1) ]

while q:
	num, dist=q.pop(0)
	#print num, dist

	if num>=LIM: continue
	if dist>=best[num]: continue
	
	best[num]=dist
	q.append( (num+1,dist+1) )

	s=str(num)[::-1]
	q.append( ( int(s),dist+1) )

'''
for z in [124,455,2422,56565,345333, LIM-1]:
	print z, best[z]
'''


'''
test=[800]*200
solve( test, 0 )
print best
'''

# ------------------------ main ------------------------------- 

k=1
case=1

while k<len(lines):
	d=int(lines[k].strip()); k+=1
	log( 'Case #%d: %d' % (case,best[d]) )
	case+=1

