T = int(input())

for t in range(T):
    A, B = map(int, input().split())

    best = 2 + B
    #print("Enter right away:", best)
    p = 1.0

    F = list(map(float, input().split()))
    
    for a in range(A):
        p *= F[a]
        
        #dist = A - a - 1
        #to_end = B - a - 1
        
        #test = p * (dist + to_end + 1) + (1 - p) * (dist + to_end + 2 + B)

        test = (A + B - 2*a - 1) + (1-p) * (B+1)

        #print("Back to", a+1, "will cost", dist, 'and will leave', to_end, 'probability', p, ':', test)
        best = min(test, best)
        
    print("Case #" + str(t+1) + ': ', best)
