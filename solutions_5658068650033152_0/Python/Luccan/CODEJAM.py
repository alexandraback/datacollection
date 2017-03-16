import math

def sol():
    global line_counter
    n,m,k = inp[line_counter].split(' ')
    line_counter+=1
    N = int(n)
    M = int(m)
    K = int(k)
    if (K<5 or min(M,N)<=2):
        return str(K)
    i = 1
    while(i**2<K and i<min(M,N)):
        i+=1
    print 'len', i
    #i is the length
    width = math.ceil(float(K)/float(i))
    ans = 0
    if (K<=(i*width)-4):
        ans = ((2*(i-1))+(2*(width-1)))-4
    else:
        ans = ((2*(i-1))+(2*(width-1)))+(K-(i*width-4))-4
        print ans
        if (width+1<=max(M,N)):
            if (ans>((2*(i-1))+(2*(width)))-4 and K<=i*(width+1)):
                ans = ((2*(i-1))+(2*(width)))-4
                print ans
    print type(ans)
    return str(int(ans))

with open('C-small-attempt1.in', 'r') as f:
#with open('LOL.txt', 'r') as f:
    inp = f.readlines()
    f.close()
line_counter = 0
T = int(inp[line_counter])
line_counter+=1
data = ''
for i in range(T):
    data += 'Case #%d:' %(i+1) + ' ' + sol()+'\n'
with open('output.txt', 'w') as f:
    f.write(data)
    f.close()
print data
print 'done!'
