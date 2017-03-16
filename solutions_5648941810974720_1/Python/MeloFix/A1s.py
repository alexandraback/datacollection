T = int(input())

a = ["ZERO", "SIX", "TWO","EIGHT", "THREE", "SEVEN", "FOUR", "ONE", "FIVE",  "NINE"]

b = ["Z", "X", "W", "G", "H", "S", "U", "O", "V", "N"]
c = [0,6,2,8,3,7,4,1,5,9]

for LoopC in range(1,T+1):
    S = input()
    A = []
    
    A += S

    nownum = 0
    
    result = [0]*10

    while(len(A)):
        if b[nownum] in A:
            for x in a[nownum]:
                A.remove(x)
            result[c[nownum]] += 1
        else:
            nownum += 1

    RET = ""

    for x in range(10):
        for y in range(result[x]):
            RET += str(x)
            
    print("Case #{}: {}".format(LoopC, RET))
