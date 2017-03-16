T = int(input())

def ooo(s):
    a = { '-':0 , '+':1 }
    return a[s]

for loopC in range(1,1+T):
    
    S = list(input())
    S = list(map(ooo,S))

    ans = 0
    
    while( 0 < S.count(0) ):
        first = S[0]
        endpoint = len(S)-1
          
        while( 0 <= endpoint ):
            
            if S[endpoint] == 0:
                break
            endpoint -= 1

        if endpoint < 0:
            break

        while( 0<= endpoint ):

            if S[endpoint] == first:
                break
            endpoint -= 1

        A = S[endpoint::-1]
        for x in range(len(A)):
            A[x] = (A[x]+1)%2
            
        S = A +S[endpoint+1:]

        ans += 1
        
        #print(A,S[endpoint+1:], endpoint)
        


    print("Case #{}: {}".format(loopC, ans))
        
