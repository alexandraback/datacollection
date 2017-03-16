# lawn mower
#inf = 100000000

def maxofcol(p,x,n):
   min = 0
   #print "x=%d and n=%d"%(x,n)
   for t in range(0,n):
      if min < p[t][x]:min=p[t][x]
     # print "t=%d and n=%d"%(t,n)
   return min

test = int (raw_input())

k = 0
while k<test :
   p=[]
   row=[]
   col=[]
   k+=1
   n,m = map( int , raw_input().split() )
   for qq1 in range(0,n):
      p.append( map( int , raw_input().split() ) )
   row = map (max , p)
   for t in range(0,m) :
      col.append( maxofcol(p,t,n) )
   flag=0
   for c in range (0, n):
    for v in range (0,m):
     if p[c][v] < row[c] and p[c][v] < col[v] :
      flag=1
      break
    if flag==1 : break
   if flag==1 : print "Case #%d: NO"%k
   else : print "Case #%d: YES"%k
#print map(max,p)
#print maxofcol(p,0,n),maxofcol(p,1,n),maxofcol(p,2,n) 
  
