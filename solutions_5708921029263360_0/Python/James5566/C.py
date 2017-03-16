t = int(input())  # read a line with a single integer
for x in range(1, t + 1):
    J, P, S, K = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
    if J * P * S == 1:
        y = 1 
    else:
        #  avoid k too large cause same clothes problem
        y = min(J * P * K, J * P * S)
    result = []
    for j in range(J):
        for p in range(P):
            for s in range(S):
                if s+1 > K:
                    break
                result.append([str(j+1), str(p+1), str(s+1)])

    print("Case #{}: {} ".format(x, y))
    # print(len(result))
    for r in result:
        print("{}".format(" ".join(r)))