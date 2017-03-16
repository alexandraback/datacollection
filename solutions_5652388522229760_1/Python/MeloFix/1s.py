T = int(input())

for loopC in range(1,1+T):
    N = int(input())

    A = [0]*10

    num = N
    for x in range(1000001):
        for y in str(num):
            A[int(y)] = 1
        if A.count(0) <= 0:
            break

        if num == num+N or x == 10e6 -1:
            num = "INSOMNIA"
            break
            
        num = num + N


    print("Case #{}: {}".format(loopC, num))
        
