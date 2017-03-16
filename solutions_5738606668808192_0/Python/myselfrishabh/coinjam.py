import itertools
from math import sqrt

def isprime(n):
    upper = int(sqrt(n))
    for i in range(2, upper+1):
        if n%i==0:
            return i;
    return -1;

def Converttodec(s, b):
        ans = 0
        for j,i in enumerate(s[::-1]):
            ans += int(i)*(b**j)
        return ans
inputf = open('C-small-attempt0.in','r')
outputf = open('coinjam-small-attempt.txt','w')
lines = inputf.readlines()      
T = int(lines[0])
for num in range(1,T+1):        
    inp = lines[num].split()
    N = int(inp[0])
    J = int(inp[1])
    outputf.write("Case #%d:\n" %num)
    for x in itertools.product(range(2), repeat = N-2):
        if J==0:
            break
        flag = 0
        div = []
        jam = '1' + ''.join([str(i) for i in x]) + '1'
        for i in range(2,11):
             j = isprime(Converttodec(jam, i))
             if j!=-1:
                 div.append(str(j))
             else:
                flag = 1
                break
        if flag==1:
            continue
        else:
           outputf.write(jam + " " + " ".join(div)+"\n")
           J-=1;
           
inputf.close()
outputf.close()