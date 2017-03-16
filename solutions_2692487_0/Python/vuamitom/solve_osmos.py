def solve(A, N, M):
    """ sole osmos """
    if A == 1:
        return len(M)
    #sort M 
    M.sort()
    sm = M
    #navigate M 
    for i in range(len(sm)):
        if A > sm[i]:
            A += sm[i]
        else:
            #2 choices, either add or remove 
            if i == len(sm) - 1:
                return 1 #just remove
            c = 0 
            while(sm[i] >= A):
                A += A-1
                c += 1
            #check if that able to solve
            A+= sm[i]
            c += solve(A, N - (i + 1), sm[(i+1):])
            if c < (len(sm) - i):
                return c
            else: 
                return (len(sm) - i)
    return 0


if __name__== "__main__":
    with open("input_small") as f:
        content = f.readlines()

    N = int(content[0])
    l = 1
    c = 1
    for case in range(0,N):
        (A, N) = [int(t) for t in content[l].split(" ")]
        M = [int(t) for t in content[l+1].split(" ")]
        print "Case #" + str(c) + ": " + str(solve(A,N,M))
        c += 1
        l += 2

    
