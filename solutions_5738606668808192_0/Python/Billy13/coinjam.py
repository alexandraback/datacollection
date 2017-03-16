import math

'''def is_not_prime(n):
    if n == 2:
        return -1
    if n % 2 == 0 or n <= 1:
        return 2

    sqr = int(math.sqrt(n)) + 1

    for divisor in range(3, sqr, 2):
        if n % divisor == 0:
            return divisor
    return -1'''

def is_not_prime(n):
  if n == 2 or n == 3:
      return 0
  if n < 2 or n%2 == 0:
      return 2
  if n < 9:
      return 0
  if n%3 == 0:
      return 3
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return f
    if n%(f+2) == 0: return f+2
    f +=6
  return 0

inp = open("in2.txt", "r")
out = open("out3.txt","w")
T= int((inp.readline()).rstrip())
for i in range(T):
    args=((inp.readline()).rstrip()).split()
    N = int(args[0])
    J = int(args[1])
    ch=[]
    for j in range(N):
        ch.append('0')
    ch[0]='1'
    ch[N-1]='1'
    inc=0
    ans=[]
    while(len(ans)!=J):
        temp=[]
        j=2
        flag=0
        while j<=10:
            k=0
            ar=0
            while k<N:
                ar+=(j**k)*(int(ch[N-1-k]))
                k+=1
            factor=is_not_prime(ar)
            if factor!=0:
                flag=1
            else:
                flag=0
            if flag == 1:
                if j==2:
                    temp.append(''.join(ch))
                    temp.append(str(factor))
                else:
                    temp.append(str(factor))
                j+=1
            else:
                break
        if flag==1:
            ans.append(temp)
        inc+=1
        if N==16:
            ttt=bin(inc)[2:].zfill(14)
        else:
           ttt=bin(inc)[2:].zfill(30)
        string='1'+str(ttt)+'1'
        ch=list(string)
    out.write("Case #" + str(i+1) + ":\n")
    for j in range(J):
        a=0
        for a in range(len(ans[j])-1):
            out.write(ans[j][a]+" ")
        out.write(ans[j][len(ans[j])-1]+"\n")