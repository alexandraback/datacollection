table = [[0 for i in xrange(40)] for i in xrange(20)]

for i in xrange(2,11):
  table[i][0]=1
  for j in xrange(1,32):
    table[i][j]=table[i][j-1]*i
    # print(table[i][j])

# print(table)


t = int(raw_input())
n,j = [int(s) for s in raw_input().split(" ")]

cont = 0

print("Case #1:")

def divisor(aux):
  aux2 = 2
  while(aux2 <= 30):
    if(aux%aux2 == 0):
     return aux2
    aux2+=1
  return 0

cont = 0
x = (1<<31)+1
# print(x)

while(cont < 500):
  jamcoin = True
  div = [0]*10
  for i in xrange(2,11):
    val = 0
    for j in xrange(0,32):
      dig = int( ((1<<j)&x)>0 )
      val += dig*table[i][j]
    # if(cont == 0):
    #   print(val)
    div[i-2] = divisor(val)
    # print(div[i-2])
    if(div[i-2]==0):
      jamcoin = False
      break
  y = 0
  for i in xrange(0,32):
    y += 10**(i)*int( ((1<<i)&x)>0 )
  if(jamcoin):
    print("{} {} {} {} {} {} {} {} {} {}".format(y,*div))
    cont+=1
  # else:
  #   print("bad\n")
  x+=2
