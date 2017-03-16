# when input is too large
#f = open("txt","r")
#def input():
#   return f.readline().strip()

def solve(B,M):
    n = B - 2
    MAX = 2**n
    if M > MAX:
        return None

    answer = [[0 for _ in range(B)] for _ in range(B)]
    for i in range(1,B):
        for j in range(i+1,B):
            answer[i][j] = 1
    #print(answer)

    if M != MAX:
        strM = str(bin(M))[2:]
        while len(strM) < n:
            strM = "0" + strM
        count = 1
        for s in strM:
            if s == "1":
                answer[0][count] = 1
            count += 1
    if M == MAX:
        for i in range(n+1):
            answer[0][i+1] = 1
    return answer

T = int(input())
O = []

for index in range(T):
    B,M = map(int, input().split())
    answer = solve(B,M)
    if not answer:
        O.append("Case #"+str(index+1)+": IMPOSSIBLE")
    else:
        O.append("Case #"+str(index+1)+": POSSIBLE")
        for i in range(len(answer)):
            temp = ""
            for j in range(len(answer)):
                temp += str(answer[i][j])
            O.append(temp)


for o in O:
    print(o)

