import math
X=open("csm.in")
z=open("output.txt","w")

def isPalindrome(number):
    number1=list(str(number))
    number2=list(str(number))
    number2.reverse()
    for index in range(0,len(number1)):
        if not number1[index]==number2[index]:
            return False
    return True

def counter(A,B,fair):
    index=0
    count=0
    while index<len(fair):
        curValue=fair[index]
        if curValue>B:
            break
        if (curValue>=A and curValue<=B):
            count+=1
        index+=1
    return str(count)

x=1
square=1
fair=[1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001L, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001]
while square<=0:
    x+=1
    square=x*x
    if isPalindrome(x) and isPalindrome(square):
        fair.append(square)


case=0
cases=int(X.readline())
while case<cases:
    case+=1
    print case
    currentline=X.readline().rstrip().lstrip().split()
    A=int(currentline[0])
    B=int(currentline[1])
    
    z.write("Case #"+str(case)+": "+counter(A,B,fair)+"\n")
    
z.close()

