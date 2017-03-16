# fair 2nd attemtp dynamic programming

class palindrome(object):
   def __init__(self,a,n):
      self.a = a
      self.n = n

def isrev(x,n):
   rev=0
   a=x
   for k in range(0,n) :
      t=x%10
      #if (t>3) : return 0
      rev*=10
      rev+=t
      x/=10
   if rev==a: return 1
   else: return 0

def check( a, b ):
   while a > 0 :
      num = a % 10
      a /= 10
      if num * b > 9 : return 0
   return 1
#pal0 = palindrome(0,1)
#pal1 = palindrome(0,1)
#pal2 = palindrome(0,1)
#pal3 = palindrome(0,1)
mainlist=[]
pal = []
pdict = {}
for x in range(0,4):
   pal.append(palindrome(x,1))
   pdict[x]=1
   if x%10 != 0 :
      mainlist.append(x*x)
for x in range(0,3):
   pal.append( palindrome(11*x,2))
   pdict[11*x]=1
   if (11*x)%10 != 0 :
      mainlist.append((x*11)*(x*11))

# build
counter=0
#for dis in range (3, 100):
while (pal[counter]).n<31:
   val = pal [counter]
   #print val.a,"===>"
   for b in range (0,3):
      #if check( val.a , 2*b ) == 1 :
      num = b + val.a*10 + b *(10**(val.n+1))
      l= num*num
      if isrev(l,2*(val.n+2)-1) : 
         pdict[num]=1
         pal.append(palindrome(num,val.n+2))
         #if num%10 != 0 : #print num
         if num % 10 != 0 : 
            mainlist.append(l)
   counter+=1
mainlist.sort()
#print mainlist,
test = int(raw_input())
n=0

while n<test :
   n+=1
   a,b = map (int, raw_input().split())
   cnter=0 
   ans=0
   while  mainlist[cnter]<=b:
      if mainlist[cnter]>=a:
         ans+=1
      cnter+=1 
   print "Case #%d: %d"%(n,ans)

