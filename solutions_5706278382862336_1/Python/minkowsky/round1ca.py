__author__ = 'Xuejun'

def gcd(a, b):
  if a < b:
    a, b = b, a

  while b != 0:
    temp = a % b
    a = b
    b = temp

  return a

casenum = int(input())

num=[]

for i in range(casenum):
    num.append(list(map(int,input().split('/'))))

for i in range(casenum):
    g=gcd(num[i][0],num[i][1])
    num[i][0]=int(num[i][0]/g)
    num[i][1]=int(num[i][1]/g)
    n=0;
    while(1):
        n=n+1;
        if num[i][0] * 2**n >= num[i][1] :
            if (num[i][0] * 2**n - num[i][1])%2 != 0 or num[i][1]%2 != 0 or (num[i][1]-1)&num[i][1] != 0:
                print('Case #{}:'.format(i+1),'impossible')
            else:
                print('Case #{}:'.format(i+1),n)
            break