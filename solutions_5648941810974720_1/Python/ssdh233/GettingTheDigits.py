# when input is too large
f = open("A-large.in.txt","r")
def input():
   return f.readline().strip()

def solve(S):
    alpha = [0 for _ in range(26)]
    for s in S:
        alpha[ord(s)-65] += 1
    #print(alpha)
    number = [0 for _ in range(10)]
    number[0] = alpha[ord("Z")-65]
    alpha[ord("Z")-65] -= number[0]
    alpha[ord("E")-65] -= number[0]
    alpha[ord("R")-65] -= number[0]
    alpha[ord("O")-65] -= number[0]
    number[2] = alpha[ord("W")-65]
    alpha[ord("T")-65] -= number[2]
    alpha[ord("W")-65] -= number[2]
    alpha[ord("O")-65] -= number[2]
    number[4] = alpha[ord("U")-65]
    alpha[ord("F")-65] -= number[4]
    alpha[ord("O")-65] -= number[4]
    alpha[ord("U")-65] -= number[4]
    alpha[ord("R")-65] -= number[4]
    number[6] = alpha[ord("X")-65]
    alpha[ord("S")-65] -= number[6]
    alpha[ord("I")-65] -= number[6]
    alpha[ord("X")-65] -= number[6]
    number[5] = alpha[ord("F")-65]
    alpha[ord("F")-65] -= number[5]
    alpha[ord("I")-65] -= number[5]
    alpha[ord("V")-65] -= number[5]
    alpha[ord("E")-65] -= number[5]
    number[8] = alpha[ord("G")-65]
    alpha[ord("E")-65] -= number[8]
    alpha[ord("I")-65] -= number[8]
    alpha[ord("G")-65] -= number[8]
    alpha[ord("H")-65] -= number[8]
    alpha[ord("T")-65] -= number[8]
    number[7] = alpha[ord("S")-65]
    alpha[ord("S")-65] -= number[7]
    alpha[ord("E")-65] -= number[7]
    alpha[ord("V")-65] -= number[7]
    alpha[ord("E")-65] -= number[7]
    alpha[ord("N")-65] -= number[7]
    number[9] = alpha[ord("I")-65]
    alpha[ord("N")-65] -= number[9]
    alpha[ord("I")-65] -= number[9]
    alpha[ord("N")-65] -= number[9]
    alpha[ord("E")-65] -= number[9]
    number[1] = alpha[ord("O")-65]
    alpha[ord("O")-65] -= number[1]
    alpha[ord("N")-65] -= number[1]
    alpha[ord("E")-65] -= number[1]
    number[3] = alpha[ord("T")-65]
    result = ""
    #print(number)
    for i in range(10):
        for j in range(number[i]):
            result += str(i)
    return result

T = int(input())
O = []

for index in range(T):
    S = input()
    O.append("Case #"+str(index+1)+": "+str(solve(S)))

for o in O:
    print(o)

