def flip(i):
    ret = 0
    while i > 0:
        ret = ret*10 + i%10
        i /= 10
    return ret

def count(N):
    C = [0]*(N+1)
    C[1] = 1
    for i in range(2, N+1):
        if flip(i) < i and flip(flip(i)) == i:
            C[i] = min(C[i-1], C[flip(i)]) + 1
        else:
            C[i] = C[i-1] + 1
    return C[N]
    

if __name__ == "__main__":
    numCases = int(raw_input())
    C = [0]*1000001
    C[1] = 1
    for i in range(2, 1000001):
        if flip(i) < i and flip(flip(i)) == i:
            C[i] = min(C[i-1], C[flip(i)]) + 1
        else:
            C[i] = C[i-1] + 1
    for c in range(numCases):
        N = int(raw_input())
        print("Case #" + str(c+1) + ": " + str(C[N]))
