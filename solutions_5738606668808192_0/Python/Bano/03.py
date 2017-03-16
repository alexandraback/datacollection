import math
num = int(input())
for i in range(num):
    print("Case #" + str(i+1) + ":")
    inp = input().split(" ")
    N = int(inp[0])
    J = int(inp[1])
    case = []
    proofs = []
    cnt = 0
    test_num = [1]
    test_num += [0 for j in range(N-2)]
    test_num.append(1)
    while True:
        proof_t = []
        for digit in range(2, 11):
            new = 0
            for k in range(len(test_num)):
                new += test_num[-(k+1)] * pow(digit, k)
            for q in range(2, round(math.sqrt(new))+1):
                if new % q == 0:
                    proof_t.append(q)
                    break
            else:
                break
        else:
            cnt += 1
            case.append(test_num[:])
            proofs.append(proof_t[:])
            if cnt == J:
                break
        for j in range(2, N):
            if test_num[-j] == 1:
                test_num[-j] = 0
            else:
                test_num[-j] = 1
                break

    for j in range(J):
        print("".join([str(t) for t in case[j]]) + " " + " ".join([str(t) for t in proofs[j]]))
