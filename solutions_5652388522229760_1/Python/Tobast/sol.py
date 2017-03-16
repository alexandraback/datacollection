def solveTest(case):
    N = int(input())
    if(N == 0):
        print("Case #"+str(case)+": INSOMNIA")
        return 

    seen = [ False for i in range(10) ]
    
    def checkDigits(k):
        while(k > 0):
            seen[k%10] = True
            k//=10
    num = 0
    while False in seen:
        num += N
        checkDigits(num)
    print("Case #"+str(case)+": "+str(num))

cases = int(input())
for c in range(cases):
    solveTest(c+1)
