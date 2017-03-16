import sys
sys.stdin = open("C-large-1.in")
#sys.stdout = open("0Cout.txt","w")
N = int(input())
def isPalindrome(x):
    if len(x)==0:
        return True
    return x[0]==x[-1] and isPalindrome(x[1:-1])
for _ in range(N):
    counted={}
    count=0
    smallSQ,largeSQ=[int(x) for x in input().split(' ')]
    #min digits in the sqrt
    mindig=len(str(int(smallSQ**0.5)))
    maxdig=len(str(int(largeSQ**0.5)))
    #min digits in my palindrome maker
    minp=int(10**(int(mindig/2)-1))
    maxp=int(10**(int(maxdig/2)+1))
    for i in range(minp,maxp):
        #print(minp,maxp)
        fin=int(str(i)+str(i)[::-1])
        #print(fin)
        if fin**2>largeSQ:
            break
        if isPalindrome(str(fin**2)) and fin**2>=smallSQ:
            count+=1
            counted[fin]=True
    for i in range(minp,maxp):
        fin=int(str(i)+str(i)[::-1][1:])
        #print(fin)
        #print(int(finstr))
        if fin**2>largeSQ:
            break
        if isPalindrome(str(fin**2)) and fin**2>=smallSQ:
            try:
                counted[fin]
            except:
                count+=1
                counted[fin]=True
    print ("Case #"+str(_+1)+": "+str(count))
#sys.stdout.close()
